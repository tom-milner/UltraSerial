//
// Created by Tom Milner on 10/05/2020.
//

#include "Receiver.h"
#include <portaudio.h>
#include <cstdlib>
#include "Config.h"
#include <string>
#include "iostream"
#include <cmath>
#include "RingBuffer.h"
#include <fftw3.h>
#include <chrono>
#include <fstream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ofstream;
using namespace std::chrono;


/// Initialise the receiver.
int Receiver::init(float ctrlFreq) {

    cout << "Initializing..." << endl;
    error = Pa_Initialize();
    if (error) return error;
    cout << error << endl;;

    inputParameters.device = Pa_GetDefaultInputDevice();
    if (inputParameters.device == 0) {
        cout << "No input device found" << endl;
        return 1;
    }


    cout << inputParameters.device << endl;

    auto info = Pa_GetDeviceInfo(inputParameters.device);
    cout << "Index: " << inputParameters.device << endl;
    cout << "Max input channels: " << info->maxInputChannels << endl;
    cout << "Max output channels: " << info->maxOutputChannels << endl;
    cout << "Device name: " << info->name << endl;


    inputParameters.channelCount = 1;
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    return 0;
}


/// This is the callback function used by portaudio to process any incoming audio.
int Receiver::processBuffer(const void *inputBuffer, void *outputBuffer, unsigned long samplesPerBuffer,
                            const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *data
) {

    ReceiveConfig *config = (ReceiveConfig *) data;
    const float *samples = (float *) inputBuffer;


    /// Read samples into ring buffer.
    for (int i = 0; i < samplesPerBuffer; i++) {
        config->rb->put(samples[i]);
    }
    return paContinue;

}


void Receiver::receive() {

    const int samplesPerBuffer = ProtocolConstants::SAMPLES_PER_BYTE / ProtocolConstants::BUFFERS_PER_BYTE;
    cout <<"Samples per buffer: " <<  samplesPerBuffer <<  endl;
    cout << "Frequency Resolution: " << ProtocolConstants::SAMPLE_RATE / samplesPerBuffer;
    error = Pa_OpenStream(
            &stream,
            &inputParameters,
            NULL,
            ProtocolConstants::SAMPLE_RATE,
            samplesPerBuffer,
            paClipOff,
            processBuffer,
            &config
    );
    cout << error << endl;

    RingBuffer<float> ringBuffer(samplesPerBuffer * 50);
    config.rb = &ringBuffer;
    error = Pa_StartStream(stream);
    cout << error << endl;


    fftw_complex *fftBuffer = (fftw_complex *) fftw_malloc(samplesPerBuffer * sizeof(fftw_complex));
    fftw_plan plan = nullptr;
    fftw_complex *out = (fftw_complex *) fftw_malloc(samplesPerBuffer * sizeof(fftw_complex));

    int lastHighest = 0;
    ofstream outFile;
    outFile.open("data.dat", std::ios::trunc);
    long lastNow = 0;
    while (Pa_IsStreamActive(stream)) {
        plan = fftw_plan_dft_1d(samplesPerBuffer, fftBuffer, fftBuffer, FFTW_FORWARD, FFTW_ESTIMATE);

        // Process samples in ring buffer one audio buffer at a time.
        for (int i = 0; i < samplesPerBuffer; i++) {
            fftBuffer[i][0] = config.rb->read();
            fftBuffer[i][1] = 0;
        }

        fftw_execute(plan);

        // Look for frequency bin with highest amplitude.
        int highest = 0;
        for (int i = 0; i < samplesPerBuffer; i++) {
            // Write frequencies to file.
//            outFile << i << " " << fftBuffer[i][0] << endl;
            if (fftBuffer[i][0] > highest) {
                highest = i;
            }
        }
        if (lastHighest != highest && highest != 0 && highest < ProtocolConstants::SAMPLE_RATE / 2) {
//            cout << highest << " " << fftBuffer[highest][0] << endl;
//            long now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
//            if (now != lastNow) {
//                outFile  << endl;
//                lastNow = now;
//            }
            outFile << highest<< "  " << fftBuffer[highest][0]  << endl;
            lastHighest = highest;
        }
    }
    outFile.close();
    fftw_destroy_plan(plan);
    fftw_free(fftBuffer);

}

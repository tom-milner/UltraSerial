//
// Created by Tom Milner on 10/05/2020.
//

#include "Receiver.h"

#include <fftw3.h>
#include <portaudio.h>
#include <cstdlib>
#include "Config.h"
#include <string>
#include "iostream"

#define HEADER_SIZE 16
#define SAMPLE_RATE   44100
#define SAMPLES_PER_BUFFER SAMPLE_RATE/2


using std::cout;
using std::cerr;
using std::endl;
using std::string;


int Receiver::init(float ctrlFreq) {

    config.sampleIndex = 0;
//    config.recordedSamples = static_cast<fftw_complex *>(fftw_malloc(
//            SAMPLES_PER_BUFFER)); // Allocate enough room for the header and a few bytes. Size will be increased once payload length is read.

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


// Read the buffer in.
int Receiver::processBuffer(const void *inputBuffer, void *outputBuffer, unsigned long samplesPerBuffer,
                            const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *data
) {
    ReceiveConfig *config = (ReceiveConfig *) data;
    const double *readPointer = (const double *) inputBuffer;

    for (int i = 0; i < samplesPerBuffer; i++) {
        config->recordedSamples[config->sampleIndex + i][0] =  *readPointer++; // Read the buffer into config.recorderSamples.
        config->recordedSamples[config->sampleIndex + i][1] =  0; // Read the buffer into config.recorderSamples.
    }
    config->sampleIndex += samplesPerBuffer;
    return paContinue;

}

void Receiver::receive() {

    error = Pa_OpenStream(
            &stream,
            &inputParameters,
            NULL,
            SAMPLE_RATE,
            SAMPLES_PER_BUFFER,
            paClipOff,
            processBuffer,
            &config
    );
    cout << error << endl;

    cout << config.sampleIndex << endl;

//    fftw_plan plan = fftw_plan_dft_1d(SAMPLES_PER_BUFFER, config.recordedSamples);

    error = Pa_StartStream(stream);
    cout << error << endl;

    while (Pa_IsStreamActive(stream)) {
        // Run fft every second.
        if (config.sampleIndex % SAMPLE_RATE == 0) {

        }
    }


}

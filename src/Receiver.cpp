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
    config.baseFreq = ctrlFreq;

    cout << inputParameters.device << endl;

    auto info = Pa_GetDeviceInfo(inputParameters.device);
    cout << "Index: " << inputParameters.device << endl;
    cout << "Max input channels: " << info->maxInputChannels << endl;
    cout << "Max output channels: " << info->maxOutputChannels << endl;
    cout << "Device name: " << info->name << endl;
    cout << "Control Frequency: " << config.baseFreq << endl;


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
    cout << "Samples per buffer: " << samplesPerBuffer << endl;
    cout << "FFT Size: " << ProtocolConstants::FFT_SIZE << endl;
    cout << "Frequency Resolution: " << ProtocolConstants::SAMPLE_RATE / ProtocolConstants::FFT_SIZE << endl;
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


    double *fftBuffer = (double *) malloc(samplesPerBuffer * sizeof(double));
    fftw_plan plan = nullptr;
    fftw_complex *out = (fftw_complex *) fftw_malloc((samplesPerBuffer / 2) + 1 * sizeof(fftw_complex));

    ofstream outFile;
    outFile.open("data.dat", std::ios::trunc);

    plan = fftw_plan_dft_r2c_1d(samplesPerBuffer, fftBuffer, out, FFTW_ESTIMATE);

    float currentSample = 0;
    while (Pa_IsStreamActive(stream)) {

        /// Add samples to fftBuffer.
        for (int i = 0; i < samplesPerBuffer; i++) {
            while (config.rb->read(&currentSample) != 0) {} ///< Wait until there are samples available.
            fftBuffer[i] = currentSample;
        }

        fftw_execute(plan);

        /// Compute average frequency amplitude.
        float average = 0;
        for (int i = 0; i < ProtocolConstants::FFT_SIZE; i++) {
            outFile << out[i][0] << "   " << out[i][1] << endl;
            average += out[i][0];
        }
        average = average / ProtocolConstants::FFT_SIZE;

        /// Calculate the standard deviation.
        float sum = 0;
        for (int i = 0; i < ProtocolConstants::FFT_SIZE; i++) {
            sum += pow(out[i][0] - average, 2);
        }
        const float stdDev = sqrt(sum / (ProtocolConstants::FFT_SIZE - 1));


        /**
         * Now we process the results of the FFT.
         * We only need to look through half of the frequencies, as the results will be symmetric around the halfway point.
         * To differentiate between active frequencies and noise, we only look at frequencies that have an energy higher than 3 standard deviations above the mean.
        * This elements 99.7% of the frequencies.
        */

        int maxFreqIdx = -1;
        float maxFreqEnergy = 0;
        const float energyThreshold = average + 3 * stdDev;
        for (int i = 0; i < ProtocolConstants::FFT_SIZE / 2; i++) {

            if (out[i][0] < energyThreshold) { ///< Check if the energy meets the threshold.
                continue; /// Ignore this frequency.
            }

            // Save the frequency with the highest energy.
            if (out[i][0] >= maxFreqEnergy) {
                maxFreqIdx = i;
                maxFreqEnergy = out[i][0];
            }

        }


//        /// Now we convert the found frequency bin into its actual frequency value in Hz.
//        const float foundFrequency = (ProtocolConstants::SAMPLE_RATE / samplesPerBuffer) * maxFreqIdx;
//        if (foundFrequency >= config.baseFreq - 100) {
//            outFile << foundFrequency << endl;
//        }

    }
    outFile.close();
    fftw_destroy_plan(plan);
    free(fftBuffer);
    fftw_free(out);

}

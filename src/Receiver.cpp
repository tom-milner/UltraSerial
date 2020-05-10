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
#define SAMPLES_PER_BUFFER 512


using std::cout;
using std::cerr;
using std::endl;
using std::string;


int Receiver::init(float ctrlFreq) {

    config.sampleIndex = 0;
    config.recordedSamples = (float *) malloc(sizeof(float) *
                                              HEADER_SIZE); // Allocate enough room for the header. Size will be increased once payload length is read.

    error = Pa_Initialize();
    if (error) return error;

    inputParameters.device = Pa_GetDefaultOutputDevice();
    if (inputParameters.device == 0) {
        cout << "No input device found" << endl;
        return 1;
    }
    inputParameters.channelCount = 1;
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    return 0;
}


int Receiver::processBuffer(const void *inputBuffer, void *outputBuffer, unsigned long samplesPerBuffer,
                            const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *data
) {
    const float *readPointer = (const float *) inputBuffer;
    const float *writePointer = (const float *) &config.recordedSamples[config.sampleIndex];


    return 0;

}

void Receiver::receive() {

    error = Pa_OpenStream(
            &stream,
            &inputParameters,
            NULL,
            SAMPLE_RATE,
            SAMPLES_PER_BUFFER,
            paClipOff,
            (std::function *) std::bind(&Receiver::processBuffer, this),
            &config
    )

}

//
// Created by Tom Milner on 10/05/2020.
//

#include "Transmitter.h"
#include "Config.h"
#include <portaudio.h>
#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

#define TABLE_SIZE 200
#define SAMPLE_RATE   44100


int Transmitter::init(float ctrlFreq, float freqDelta) {

    float controlFrequency = ctrlFreq;
    float highFrequency = controlFrequency + freqDelta;
    float lowFrequency = controlFrequency - freqDelta;

    config.highPhaseStep = calculatePhaseStep(highFrequency);
    config.lowPhaseStep = calculatePhaseStep(lowFrequency);
    config.controlPhaseStep = calculatePhaseStep(controlFrequency);

    // Generate wavetable.
    generateWavetable(&config);
    config.phase = 0;

    error = Pa_Initialize();
    if (error) return error;

    outputParameters.device = Pa_GetDefaultOutputDevice();
    if (outputParameters.device == paNoDevice) {
        cout << "No audio device found." << endl;
        return 1;
    }

    outputParameters.channelCount = 1;
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = nullptr;

    return 0;
}


void Transmitter::transmit(char *data, int dataLength) {


    const int samplesPerBit = SAMPLE_RATE / 4;
    const int samplesPerControl = SAMPLE_RATE / 16;

    const unsigned long bufferLength = dataLength * 8 * (samplesPerBit + samplesPerControl );
    float *buffer = (float *) malloc(sizeof(float) * bufferLength);

    // fill buffer.
    int bIndex = 0;
    for (int i = 0; i < dataLength; i++) {
        int bitCounter = 0;
        char currByte = *data;
        while (bitCounter < 8) {
            int currBit = currByte & 0x01;
//            for (int k = 0; k < samplesPerControl; k++) {
//                buffer[bIndex] = getNextSineSample(&config, 2);
//                bIndex++;
//            }
            for (int k = 0; k < samplesPerBit; k++) {
                buffer[bIndex] = getNextSineSample(&config, currBit);
                bIndex++;
            }
            for (int k = 0; k < samplesPerControl; k++) {
                buffer[bIndex] = 0;
                bIndex++;
            }
            currByte = currByte >> 1;
            bitCounter++;
        }
        data++;
    }


    error = Pa_OpenStream(
            &stream,
            NULL,
            &outputParameters,
            SAMPLE_RATE,
            0,
            paClipOff,
            nullptr,
            nullptr
    );
    if (error) cout << "Error opening stream" << endl;

    error = Pa_StartStream(stream);

    cout << "Transmitting... " << endl;
    Pa_WriteStream(stream, buffer, bufferLength);

    error = Pa_StopStream(stream);
    if (error) cout << ("Error stopping stream.") << endl;
    free(buffer);


    error = Pa_CloseStream(stream);
    if (error) cout << ("Error closing stream") << endl;

    Pa_Terminate();

}

void Transmitter::generateWavetable(TransmitConfig *config) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        config->sine[i] = (float) sin(((double) i / (double) TABLE_SIZE) * M_PI *
                                      2); // /TABLE_SIZE to keep scale factor between 1 and 0
    }
}

float Transmitter::calculatePhaseStep(float targetFreq) {
    return targetFreq / (SAMPLE_RATE / TABLE_SIZE);
}

float Transmitter::getNextSineSample(TransmitConfig *config, int level) {
    int currIndex = (unsigned int) config->phase;
    int nextIndex = currIndex == TABLE_SIZE - 1 ? (unsigned int) 0 : currIndex + 1;
    float frac = config->phase - currIndex;
    float sample = config->sine[currIndex] + frac * (config->sine[nextIndex] - config->sine[currIndex]);

    if (!level) {
        config->phase += config->lowPhaseStep;
    } else if (level == 1) {
        config->phase += config->highPhaseStep;
    } else {
        config->phase += config->controlPhaseStep;
    }

    if (config->phase >= TABLE_SIZE) config->phase -= TABLE_SIZE; // % could be used here.
    return sample;
}



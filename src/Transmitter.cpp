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
#define FREQUENCY_INTERVAL 50
#define RAMP_SAMPLES 500


int Transmitter::init(float ctrlFreq) {

    float controlFrequency = ctrlFreq;
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


    const int samplesPerBit = SAMPLE_RATE / 16;
    const int samplesPerControl = SAMPLE_RATE / 64;

    const unsigned long bufferLength = dataLength * (samplesPerBit + samplesPerControl * 2) + 2 * RAMP_SAMPLES;
    float *buffer = (float *) malloc(sizeof(float) * bufferLength);

    // fill buffer.
    int bIndex = 0;

    for (int i = 0; i < dataLength; i++) {
        cout << unsigned((uint8_t) data[i]) << endl;

        // "Ramp Up/Down" to target frequency.
        if (i != 0) {
            float currStep = calculatePhaseStep(FREQUENCY_INTERVAL * (uint8_t) data[i - 1]);
            float targetPhaseStep = calculatePhaseStep(FREQUENCY_INTERVAL * (uint8_t) data[i]);
            float stepPerSample = (targetPhaseStep - currStep) / samplesPerControl;
            for (int k = 0; k < samplesPerControl; k++) {
                currStep += stepPerSample;
                float sf = getAmplitudeScaleFactor(k,samplesPerControl,0.2);
                buffer[bIndex] = getNextSineSample(&config, (uint8_t) data[i], currStep) * sf;
                bIndex++;
            }
        }
        for (int k = 0; k < samplesPerBit; k++) {
            buffer[bIndex] = getNextSineSample(&config, (uint8_t) data[i]);
            bIndex++;
        }
    }

    // Add a few samples on the end to make it cut out nicely.
    for (int i = 0; i < RAMP_SAMPLES; i++) {
        buffer[bIndex] = buffer[bIndex - 1] / 2;
        bIndex++;
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

float Transmitter::getAmplitudeScaleFactor(int x, float max, float min) {
    float f = pow((x - max/2)/(max/2), 2);
    float g = -min * pow((x - max/2)/(max/2), 2) + min;
    return f+g;
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

float Transmitter::getNextSineSample(TransmitConfig *config, uint8_t data, float step) {
    config->phase += config->controlPhaseStep + (step == 0 ? calculatePhaseStep(data * FREQUENCY_INTERVAL) : step);
    if (config->phase >= TABLE_SIZE) config->phase -= TABLE_SIZE; // % could be used here.


    int currIndex = (unsigned int) config->phase;
    int nextIndex = currIndex == TABLE_SIZE - 1 ? (unsigned int) 0 : currIndex + 1;
    float frac = config->phase - currIndex;
    float sample = config->sine[currIndex] + frac * (config->sine[nextIndex] - config->sine[currIndex]);

    return sample;
}



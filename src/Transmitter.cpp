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

#define RAMP_SAMPLES 500 /**< The number of samples to use to "ramp" up/down the signal.
 * This is only used to make the audio sound nicer.
 * I'm using "ramping" to describe either increasing the amplitude from 0 to 1 (up) or vice-versa (down).
 * */


/**
 *  Set up the transmitter.
 *  \param ctrlFreq - The frequency for the '0' character.
 *  \return integer representing the status of the transmitter. Non-zero if an error has occurred.
 */
int Transmitter::init(float ctrlFreq) {

    float controlFrequency = ctrlFreq;
    config.controlPhaseStep = calculatePhaseStep(controlFrequency);


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
    outputParameters.sampleFormat = paFloat32; ///< Each sample needs to be a 32-bit float.
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = nullptr;

    return 0;
}

/**
 * Transmit the supplied characters.
 * \param data - the characters to transmit.
 * \param dataLength - the amount of characters to transmit.
 * */
void Transmitter::transmit(char *data, int dataLength) {


    /// Initialise the audio buffer with the length of the data, plus the number of bridge samples, plus the ramp samples.
    const unsigned long bufferLength = dataLength * (ProtocolConstants::SAMPLES_PER_BYTE + ProtocolConstants::SAMPLES_PER_BRIDGE) + RAMP_SAMPLES;
    float *buffer = (float *) malloc(sizeof(float) * bufferLength); ///< One float per sample.


    /**
     * Here we turn the characters into samples.
     * We use one frequency band per byte. Therefore, the protocol uses 255 different frequencies.
     * The size of each frequency band is determined by FREQUENCY_INTERVAL.
     */
    int bIndex = 0; ///< b(uffer)Index -  The index of the current sample in the buffer.
    for (int i = 0; i < dataLength; i++) {

        /// Step to next frequency, and lower the amplitude as we do so.
        float targetPhaseStep = calculatePhaseStep(ProtocolConstants::FREQUENCY_INTERVAL *
                                                   (uint8_t) data[i]); ///< The phase step we need to get to to reach the target frequency for the byte.

        if (i != 0) { ///< We don't need to slowly step to the right frequency with the first byte.
            float stepPerSample = (targetPhaseStep - config.currPhaseStep) /
                                  ProtocolConstants::SAMPLES_PER_BRIDGE; ///< The amount of phase to step for each sample.
            for (int k = 0; k < ProtocolConstants::SAMPLES_PER_BRIDGE; k++) {
                config.currPhaseStep += stepPerSample; ///< Increase/Decrease the current phase step until we reach the required frequency.
//                float amplitudeScaleFactor = getAmplitudeScaleFactor(k, ProtocolConstants::SAMPLES_PER_BRIDGE,
//                                                                     0.8); ///< We also reduce (and then increase) the amplitude during this stepping process - just for aesthetics!
//                buffer[bIndex] = getNextSineSample(&config) * amplitudeScaleFactor;
                buffer[bIndex] = getNextSineSample(&config);
                bIndex++;
            }
        }

        /// Now we have reached the target frequency, write the samples of this frequency to the buffer.
        for (int k = 0; k < ProtocolConstants::SAMPLES_PER_BYTE; k++) {
            config.currPhaseStep = targetPhaseStep;
            buffer[bIndex] = getNextSineSample(&config);
            bIndex++;
        }
    }

    /** "Ramp Down" the end of the signal so it doesn't sound as horrible.
     * This is done by repeating the final sample whilst scaling down its amplitude.
    */
    for (int i = 0; i < RAMP_SAMPLES; i++) {
        buffer[bIndex] = buffer[bIndex - 1] * getAmplitudeScaleFactor(i, RAMP_SAMPLES * 2,
                                                                      0); ///< 'getAmplitudeScaleFactor' usually goes from 1 -> 0 -> 1. Here, we just want it to go to zero;
        bIndex++;
    }

/// The full buffer has been created!! Write it to an audio stream.
    error = Pa_OpenStream(
            &stream,
            NULL,
            &outputParameters,
            ProtocolConstants::SAMPLE_RATE,
            0,
            paClipOff,
            nullptr,
            nullptr
    );
    if (error) cout << "Error opening stream" << endl;

    error = Pa_StartStream(stream);

    cout << "Transmitting... " << endl;
    Pa_WriteStream(stream, buffer, bufferLength); ///< This is a blocking operation.

    error = Pa_StopStream(stream);
    if (error) cout << ("Error stopping stream.") << endl;
    free(buffer);


    error = Pa_CloseStream(stream);
    if (error) cout << ("Error closing stream") << endl;

    Pa_Terminate();

}

/// Scale the ampitude between 1 and minAmplitude depending on x.
/// https://www.desmos.com/calculator/knngasmlah
/// \param minAmplitude - The minimum amplitude to scale down to (0 ->1).
/// \param totalSamples - The number of samples to scale.
/// \param x - The current sample number (0 -> totalSamples).
float Transmitter::getAmplitudeScaleFactor(int x, float totalSamples, float minAmplitude) {
    float f = pow((x - totalSamples / 2) / (totalSamples / 2), 2); ///< This is a quadratic anchored at (0,1) and (totalSamples,1).
    return f * (1-minAmplitude) + minAmplitude; ///< Adjust the graph to have  higher turning point (the value of minAmplitude).
}

/// Generate a simple wavetable containing a sin wave.
void Transmitter::generateWavetable(TransmitConfig *config) {
    for (int i = 0; i < ProtocolConstants::TABLE_SIZE; i++) {
        config->sine[i] = (float) sin(((double) i / (double) ProtocolConstants::TABLE_SIZE) * M_PI *
                                      2); // /ProtocolConstantsTABLE_SIZE to keep scale factor between 1 and 0
    }
}

/// Calculate how much we need to step through the wavetable to produce the target frequency.
/// \return A 'scale factor' determining how many many samples must be stepped through at once to reach the desired frequency.
float Transmitter::calculatePhaseStep(float targetFreq) {
    /// SAMPLE_RATE / ProtocolConstants::TABLE_SIZE = frequency of stepping through the wavetable point by point.
    return targetFreq / (ProtocolConstants::SAMPLE_RATE / ProtocolConstants::TABLE_SIZE); /// a scale factor.
}

/// Get the sample produced by the current config (phase step).
float Transmitter::getNextSineSample(TransmitConfig *config) {
    config->phase += config->controlPhaseStep + config->currPhaseStep;
    if (config->phase >= ProtocolConstants::TABLE_SIZE) config->phase -= ProtocolConstants::TABLE_SIZE; // % could be used here.

    /// Interpolate to get the correct sample, as the new phase may not be a while number (therefore cannot be used as an index of the wavetable).
    int currIndex = (unsigned int) config->phase;
    int nextIndex = currIndex == ProtocolConstants::TABLE_SIZE - 1 ? (unsigned int) 0 : currIndex + 1;
    float frac = config->phase - currIndex;
    float sample = config->sine[currIndex] + frac * (config->sine[nextIndex] - config->sine[currIndex]);
    return sample;
}



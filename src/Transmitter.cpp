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


/**
 *  Set up the transmitter.
 *  \param ctrlFreq - The frequency for the '0' character.
 *  \return integer representing the status of the transmitter. Non-zero if an error has occurred.
 */
int Transmitter::init(float ctrlFreq) {

    config.baseFreq = ctrlFreq;



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
    const unsigned long bufferLength = dataLength * (ProtocolConstants::SAMPLES_PER_BYTE);
    float *buffer = (float *) malloc(sizeof(float) * bufferLength); ///< One float per sample.

    cout << ProtocolConstants::SAMPLES_PER_BYTE << endl;
    /**
     * Here we turn the characters into samples.
     * We use one frequency band per byte. Therefore, the protocol uses 255 different frequencies.
     * The size of each frequency band is determined by FREQUENCY_INTERVAL.
     */
    int bIndex = 0; ///< b(uffer)Index -  The index of the current sample in the buffer.
    config.currPhaseStep = calculatePhaseStep(ProtocolConstants::FREQUENCY_INTERVAL * (uint8_t) data[0]); ///< The phase step we need for the target frequency for the byte.
    for (int i = 0; i < dataLength; i++) {
        cout << "tf: " <<ProtocolConstants::FREQUENCY_INTERVAL * (uint8_t) data[i] << " - " << data[i] << endl;
        /// Write the samples of this frequency to the first 90% of the buffer;
        int frequencyChangePoint = ProtocolConstants::SAMPLES_PER_BYTE * 0.85;
        int k = 0;
        for (; k < frequencyChangePoint; k++) {
            buffer[bIndex++] = getNextSineSample(&config) * getAmplitudeScaleFactor(k, ProtocolConstants::SAMPLES_PER_BYTE, 0.2);
        }

        /// Now start changing to the frequency of the next sample.
        if(i != dataLength -1) {
            float nextPhaseStep = calculatePhaseStep(ProtocolConstants::FREQUENCY_INTERVAL * (uint8_t) data[i + 1]);
            float stepsPerSample = (nextPhaseStep - config.currPhaseStep) / (ProtocolConstants::SAMPLES_PER_BYTE - frequencyChangePoint);
            for (; k < ProtocolConstants::SAMPLES_PER_BYTE; k++) {
                config.currPhaseStep += stepsPerSample;
                buffer[bIndex++] =
                        getNextSineSample(&config) * getAmplitudeScaleFactor(k, ProtocolConstants::SAMPLES_PER_BYTE, 0.2);
            }
            config.currPhaseStep = nextPhaseStep;
        }
    }

/// The full buffer has been created!! Write it to an audio stream.
    error = Pa_OpenStream(
            &stream,
            NULL,
            &outputParameters,
            ProtocolConstants::SAMPLE_RATE,
            0, ///< Put all the frames in one buffer!!
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
/// https://www.desmos.com/calculator/96tyqycvcz
/// \param minAmplitude - The minimum amplitude to scale down to (0 ->1).
/// \param totalSamples - The number of samples to scale.
/// \param x - The current sample number (0 -> totalSamples).
float Transmitter::getAmplitudeScaleFactor(int x, float totalSamples, float minAmplitude) {
//    float f = pow((x - totalSamples / 2) / (totalSamples / 2), 2); ///< This is a quadratic anchored at (0,1) and (totalSamples,1). EDIT: Not anymore!! checkout link ^^^
//    return f * (1-minAmplitude) + minAmplitude; ///< Adjust the graph to have  higher turning point (the value of minAmplitude).
    float d = 2.2;
    float s = 25;
    float a = pow(((d * x) / totalSamples) - (d / 2), 2 * s);
    return ((1 - minAmplitude) / (1 + a)) + minAmplitude;
}

/// Generate a simple wavetable containing a sin wave.
void Transmitter::generateWavetable(TransmitConfig *config) {
    for (int i = 0; i < ProtocolConstants::TABLE_SIZE; i++) {
        config->sine[i] = (float) sin(((double) i / (double) ProtocolConstants::TABLE_SIZE) * M_PI * 2); //  /ProtocolConstants::TABLE_SIZE to keep scale factor between 1 and -1
    }
}

/// Calculate how much we need to step through the wavetable to produce the target frequency.
/// \return A 'scale factor' determining how many many samples must be stepped through at once to reach the desired frequency.
float Transmitter::calculatePhaseStep(float targetFreq) {

    /// SAMPLE_RATE / ProtocolConstants::TABLE_SIZE = frequency of stepping through the wavetable point by point.
    return ((targetFreq + config.baseFreq) / (ProtocolConstants::SAMPLE_RATE / ProtocolConstants::TABLE_SIZE)) ; /// a scale factor.
}

/// Get the sample produced by the current config (phase step).
float Transmitter::getNextSineSample(TransmitConfig *config) {
    config->phase +=  config->currPhaseStep;
    if (config->phase >= ProtocolConstants::TABLE_SIZE) config->phase -= ProtocolConstants::TABLE_SIZE; // % could be used here.

    /// Interpolate to get the correct sample, as the new phase may not be a whole number (therefore cannot be used as an index of the wavetable).
    int currIndex = (unsigned int) config->phase % ProtocolConstants::TABLE_SIZE;
    int nextIndex = currIndex == ProtocolConstants::TABLE_SIZE - 1 ? (unsigned int) 0 : currIndex + 1;
    float frac = config->phase - currIndex;
    float sample = config->sine[currIndex] + frac * (config->sine[nextIndex] - config->sine[currIndex]);
    return sample;
}



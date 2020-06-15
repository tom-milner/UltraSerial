//
// Created by Tom Milner on 10/05/2020.
//

#include "Transmitter.h"
#include "Config.h"
#include <portaudio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <chrono>

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
 * Turn a character buffer into audio samples using the method specified.
 * @param data - The character buffer to transform.
 * @param samples - The buffer to write the generated samples to.
 * @param dataLength - Length of the character buffer.
 * @param method - The modulation method to use (defaults to 0).
 */
void Transmitter::binToSamples(char *data, float *samples, int dataLength, uint8_t method) {

    int sIndex = 0;
    int frequencyChangePoint = 0.85 * ProtocolConstants::SAMPLES_PER_DATA;

    // Add the start frequency.
    config.currPhaseStep = calculatePhaseStep(ProtocolConstants::START_FREQUENCY);

    for (int k = 0; k < ProtocolConstants::SAMPLES_PER_DATA * 2; k++) {
        samples[sIndex++] = getNextSineSample(&config) * getAmplitudeScaleFactor(k, ProtocolConstants::SAMPLES_PER_DATA * 2, 0.2);
    }

    /// Nibble modulator. 4 bytes encoded in each frequency.
    if (method == 0) {

        uint8_t currNibble, nextNibble;
        nextNibble = currNibble = data[0] >> 4; ///< The first nibble in the sequence.

        config.currPhaseStep = calculatePhaseStep(config.baseFreq + (currNibble * ProtocolConstants::FREQUENCY_INTERVAL));
        for (int i = 0; i < dataLength; i++) {
            cout << endl << data[i] << "    " << byteToBinary(data[i]) << endl;
            for (int j = 0; j < 2; j++) { ///< Half a byte at a time.

                /// Move to the next nibble.
                currNibble = nextNibble;
                if (!(j == 1 && i == dataLength - 1)) {
                    nextNibble = (j == 1 ? data[i + 1] >> 4 : data[i] & 0xF);
                }

                cout << (int) currNibble << "    " << byteToBinary(currNibble) << "    " << config.baseFreq + (currNibble * ProtocolConstants::FREQUENCY_INTERVAL) << endl;

                /// Step to the next frequency.
                float nextPhaseStep = calculatePhaseStep((nextNibble * ProtocolConstants::FREQUENCY_INTERVAL) + config.baseFreq);
                float stepsPerSample = (nextPhaseStep - config.currPhaseStep) / (ProtocolConstants::SAMPLES_PER_DATA - frequencyChangePoint);

                for (int k = 0; k < ProtocolConstants::SAMPLES_PER_DATA; k++) {
                    if (k > frequencyChangePoint) {
                        config.currPhaseStep += stepsPerSample;
                    }
                    samples[sIndex++] = getNextSineSample(&config) * getAmplitudeScaleFactor(k, ProtocolConstants::SAMPLES_PER_DATA, 0.2);
                }


            }
        }


        float nextPhaseStep = calculatePhaseStep(ProtocolConstants::STOP_FREQUENCY);
        float stepsPerSample = (nextPhaseStep - config.currPhaseStep) / (ProtocolConstants::SAMPLES_PER_DATA - frequencyChangePoint);
        for (int i = 0; i < ProtocolConstants::SAMPLES_PER_DATA * 2; i++) {
            if (i < ProtocolConstants::SAMPLES_PER_DATA - frequencyChangePoint) { config.currPhaseStep += stepsPerSample; }
            samples[sIndex++] = getNextSineSample(&config) * getAmplitudeScaleFactor(i, ProtocolConstants::SAMPLES_PER_DATA * 2, 0.2);
        }

    } else {
        cout << "Modulation method not supported." << endl;
    }
}


/**
 * Transmit the supplied characters.
 * \param data - the characters to transmit.
 * \param dataLength - the amount of characters to transmit.
 * */
void Transmitter::transmit(char *data, int dataLength) {


    /// Initialise the audio buffer with the length of the data, plus the number of bridge samples.
    const unsigned long bufferLength = ((dataLength + 4) * (ProtocolConstants::SAMPLES_PER_DATA) * 2);
    float *buffer = (float *) malloc(sizeof(float) * bufferLength); ///< One float per sample.

    cout << ProtocolConstants::SAMPLES_PER_DATA << endl;


    // Using the new byte-at-a-time technique.
    // The base frequency is the frequency of the least significant bit.
    // The bit position n is given a frequency of (n * FREQUENCY_INTERVAL) + base frequency (little-endian).
    // int bIndex = 0; ///< Index of the current sample in the buffer.

    // Calculate the phase step for each nit position.
//    float bitPhaseSteps[8] = {0};
//    for (int i = 0; i < 8; i++) {
//        bitPhaseSteps[i] = calculatePhaseStep(config.baseFreq + (i * ProtocolConstants::FREQUENCY_INTERVAL));
//        cout << config.baseFreq + (i * ProtocolConstants::FREQUENCY_INTERVAL) << endl;
//    }

    // Create the samples for each bit.
//    for (int i = 0; i < dataLength; i++) {
//        cout << data[i] << endl;
//        for (int j = 0; j < 8; j++) {
//
//            if (data[i] & (0x01 << j)) {
//                cout << "1";
//                config.currPhaseStep = bitPhaseSteps[j];
//                // Write the samples.
//                for (int k = 0; k < ProtocolConstants::SAMPLES_PER_BYTE; k++) {
//                    buffer[bIndex + k] += 0.5 * getNextSineSample(&config) * getAmplitudeScaleFactor(k, ProtocolConstants::SAMPLES_PER_BYTE, 0.2);
//                }
//            } else {
//                cout << "0";
//            }
//        }
//        cout << endl;
//        bIndex += ProtocolConstants::SAMPLES_PER_BYTE;
//        // Write the byte samples to the buffer.
//    }

    binToSamples(data, buffer, dataLength, 0);


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

    cout << std::chrono::system_clock::now().time_since_epoch().count() << endl;
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
    float d = 1.15; ///< Length of "table" relative to totalSamples.
    float a = 22; ///< "Squareness" of corners.
    float k = pow(((5 / (2 * d)) * ((x / totalSamples) - 0.5)), 2 * a);
    return ((1 - minAmplitude) / (1 + k)) + minAmplitude;
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
    return ((targetFreq) / (ProtocolConstants::SAMPLE_RATE / ProtocolConstants::TABLE_SIZE)); /// a scale factor.
}

/// Get the sample produced by the current config (phase step).
float Transmitter::getNextSineSample(TransmitConfig *config) {
    config->phase += config->currPhaseStep;
    if (config->phase >= ProtocolConstants::TABLE_SIZE) config->phase -= ProtocolConstants::TABLE_SIZE; // % could be used here.

    /// Interpolate to get the correct sample, as the new phase may not be a whole number (therefore cannot be used as an index of the wavetable).
    int currIndex = (unsigned int) config->phase % ProtocolConstants::TABLE_SIZE;
    int nextIndex = currIndex == ProtocolConstants::TABLE_SIZE - 1 ? (unsigned int) 0 : currIndex + 1;
    float frac = config->phase - currIndex;
    float sample = config->sine[currIndex] + frac * (config->sine[nextIndex] - config->sine[currIndex]);
    return sample;
}

string Transmitter::byteToBinary(char byte) {
    string out;
    for (int i = 0; i < 8; i++) {
        out += (byte & (0x80 >> i)) ? "1" : "0";
    }
    return out;
}


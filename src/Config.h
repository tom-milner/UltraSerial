//
// Created by Tom Milner on 10/05/2020.
//

#ifndef ULTRASERIAL_CONFIG_H
#define ULTRASERIAL_CONFIG_H

#include <cstdlib>
#include "RingBuffer.h"

#define NIBBLE_ENCODING 1
#define BIT_ENCODING 2

/// These may seem like magic numbers - they're not!!
namespace ProtocolConstants {
    const int FREQUENCY_RESOLUTION = 345;/// 345Hz is a frequency resolution that works quite well (lots of testing!!). This needs to be a integer
    const int TABLE_SIZE = 200;
    const float FREQUENCY_INTERVAL = FREQUENCY_RESOLUTION * 2; // '*2' means that EVERY OTHER FREQUENCY BIN of the FFT represents a nibble.
    const int SAMPLE_RATE = 44160; /// Not the standard 44100 so that we can we have an integer frequency resolution.
    const int SAMPLES_PER_DATA = 4096 * 2; ///< The number of samples to send for each byte.
    const int START_FREQUENCY = (19 * FREQUENCY_INTERVAL); /// Higher than the max nibble frequency (15 * FREQUENCY_INTERVAL)
    const int STOP_FREQUENCY = (17 * FREQUENCY_INTERVAL);
    const int SAMPLES_PER_BUFFER = 128; /// Larger FFT -> Higher Frequency Resolution. Preferably a power of 2!!
}


/// Used to pass around data in the transmitter.
struct TransmitConfig {
    float sine[ProtocolConstants::TABLE_SIZE]; /// The sine wave-table.
    float phase; /// The current phase int the table.
    float baseFreq; /// The minimum frequency to transmit at.
    float currPhaseStep; /// The current phase step.
    uint8_t encoding; /// The type of encoding/modulation to use.
};


/// Used to pass around data in the receiver.
struct ReceiveConfig {
    RingBuffer<float> *rb; /// The ring buffer containing the audio samples to process.
    float baseFreq; /// The minimum frequency to receive at.
    char inDataStream = 0; /// Whether or not we have heard the start bit and are in the data stream or not.
    int sampleCount = 0; /// The number of samples we have processed so far. Used as a clock.
    uint8_t encoding; /// The type of encoding/modulation to use.
};


#endif //ULTRASERIAL_CONFIG_H

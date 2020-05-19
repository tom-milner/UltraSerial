//
// Created by Tom Milner on 10/05/2020.
//

#ifndef ULTRASERIAL_CONFIG_H
#define ULTRASERIAL_CONFIG_H

#include <fftw3.h>
#include <stdlib.h>


namespace ProtocolConstants {
    const int TABLE_SIZE = 200;
    const int HEADER_SIZE = 16;
    const int FREQUENCY_INTERVAL = 50;
    const int SAMPLE_RATE = 44100;
    const int SAMPLES_PER_BYTE = SAMPLE_RATE / 16; ///< The number of samples to send for each byte.
    const int SAMPLES_PER_BRIDGE = SAMPLE_RATE /
                                   64; ///< The number of samples to use for 'bridging' between one character and the next in transmission.
    const int BUFFERS_PER_CELL = 16;
};

struct TransmitConfig {
    float sine[ProtocolConstants::TABLE_SIZE];
    float phase;
    float controlPhaseStep;
    float currPhaseStep;
};

struct ReceiveConfig {
    uint8_t inSignal;
    uint8_t bufferCounter;
    char * receivedChars;
};


#endif //ULTRASERIAL_CONFIG_H

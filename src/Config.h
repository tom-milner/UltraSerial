//
// Created by Tom Milner on 10/05/2020.
//

#ifndef ULTRASERIAL_CONFIG_H
#define ULTRASERIAL_CONFIG_H

#include <cstdlib>
#include "RingBuffer.h"


namespace ProtocolConstants {
    const int TABLE_SIZE = 200;
    const int HEADER_SIZE = 16;
    const int FREQUENCY_INTERVAL = 500 ;
    const int SAMPLE_RATE = 44100;
    const int SAMPLES_PER_BYTE = 4096*2; ///< The number of samples to send for each byte.
    const int BUFFERS_PER_BYTE = 4;
};

struct TransmitConfig {
    float sine[ProtocolConstants::TABLE_SIZE];
    float phase;
    float baseFreq;
    float currPhaseStep;
};

struct ReceiveConfig {
    RingBuffer<float>  * rb;
};


#endif //ULTRASERIAL_CONFIG_H

//
// Created by Tom Milner on 10/05/2020.
//

#ifndef ULTRASERIAL_CONFIG_H
#define ULTRASERIAL_CONFIG_H

#include <fftw3.h>
#include <cstdlib>


namespace ProtocolConstants {
    const int TABLE_SIZE = 200;
    const int HEADER_SIZE = 16;
    const int FREQUENCY_INTERVAL = 50;
    const int SAMPLE_RATE = 44100;
    const int SAMPLES_PER_BYTE = 4096; ///< The number of samples to send for each byte.
    const int BUFFERS_PER_BYTE = 4;
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
    int lastFreq;
    fftw_plan plan;
    fftw_complex * fftBuffer;
};


#endif //ULTRASERIAL_CONFIG_H

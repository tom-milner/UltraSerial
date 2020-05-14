//
// Created by Tom Milner on 10/05/2020.
//

#ifndef ULTRASERIAL_CONFIG_H
#define ULTRASERIAL_CONFIG_H

#include <fftw3.h>

#define TABLE_SIZE 200

struct TransmitConfig {
    float sine[TABLE_SIZE];
    float phase;
    float highPhaseStep;
    float lowPhaseStep;
    float controlPhaseStep;
};

struct ReceiveConfig {
    int sampleIndex; // Our current index in the sample array.
    fftw_complex * recordedSamples;
};


#endif //ULTRASERIAL_CONFIG_H

//
// Created by Tom Milner on 10/05/2020.
//

#ifndef ULTRASERIAL_CONFIG_H
#define ULTRASERIAL_CONFIG_H


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
    float * recordedSamples;
};


#endif //ULTRASERIAL_CONFIG_H

//
// Created by Tom Milner on 10/05/2020.
//

#ifndef ULTRASERIAL_TRANSMITTER_H
#define ULTRASERIAL_TRANSMITTER_H


#include <portaudio.h>
#include <string>
#include "Config.h"

class Transmitter {

public:

    void transmit(char *data, int dataLength);

    int init(float ctrlFreq);

private:
    float getNextSineSample(TransmitConfig *config);

    float calculatePhaseStep(float targetFreq);

    float getAmplitudeScaleFactor(int x, float totalSamples, float minAmplitude);

    void generateWavetable(TransmitConfig *config);
    PaStream *stream;
    PaStreamParameters outputParameters;
    PaError error;
    TransmitConfig config;
};
#endif //ULTRASERIAL_TRANSMITTER_H

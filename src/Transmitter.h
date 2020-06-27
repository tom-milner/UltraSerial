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

    int init(float ctrlFreq, int method);

private:
    float getNextSineSample();

    void dataToSamples(char *data, float *samples, int dataLength);

    float calculatePhaseStep(float targetFreq);

    float getAmplitudeScaleFactor(int x, float totalSamples, float minAmplitude);

    std::string byteToBinary(char byte);

    void generateWavetable();


    PaStream *stream;
    PaStreamParameters outputParameters;
    PaError error;
    TransmitConfig transmitConfig;
};

#endif //ULTRASERIAL_TRANSMITTER_H

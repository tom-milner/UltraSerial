//
// Created by Tom Milner on 10/05/2020.
//

#ifndef ULTRASERIAL_RECEIVER_H
#define ULTRASERIAL_RECEIVER_H


#include <portaudio.h>
#include "Config.h"

class Receiver {

public:
 int init(float ctrlFreq);

 void receive();


private:
    ReceiveConfig config;
    PaError error;
    PaStream *stream;
    PaStreamParameters inputParameters;

    int processBuffer(const void *inputBuffer, void *outputBuffer, unsigned long samplesPerBuffer,
                      const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *data);
};


#endif //ULTRASERIAL_RECEIVER_H

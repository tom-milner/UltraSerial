//
// Created by Tom Milner on 10/05/2020.
//

#ifndef ULTRASERIAL_RECEIVER_H
#define ULTRASERIAL_RECEIVER_H


#include <portaudio.h>
#include <fstream>
#include "Config.h"


class Receiver {

public:
    int init(float ctrlFreq, uint8_t encoding);

    void receive();


private:
    ReceiveConfig receiveConfig;
    PaError error;
    PaStream *stream;
    std::ofstream outFile;
    PaStreamParameters inputParameters;

    static int processBuffer(const void *inputBuffer, void *outputBuffer, unsigned long samplesPerBuffer,
                             const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *data);


    std::string byteToBinary(char byte);

    char compareFrequencies(float f1, float f2);

    uint8_t  nibbleDecode(float foundFrequency);


    void bitDecode();
};


#endif //ULTRASERIAL_RECEIVER_H

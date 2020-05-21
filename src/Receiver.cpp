//
// Created by Tom Milner on 10/05/2020.
//

#include "Receiver.h"

#include <portaudio.h>
#include <cstdlib>
#include "Config.h"
#include <string>
#include "iostream"
#include <cmath>


using std::cout;
using std::cerr;
using std::endl;
using std::string;

/// Initialise the receiver.
int Receiver::init(float ctrlFreq) {

    cout << "Initializing..." << endl;
    error = Pa_Initialize();
    if (error) return error;
    cout << error << endl;;

    inputParameters.device = Pa_GetDefaultInputDevice();
    if (inputParameters.device == 0) {
        cout << "No input device found" << endl;
        return 1;
    }


    cout << inputParameters.device << endl;

    auto info = Pa_GetDeviceInfo(inputParameters.device);
    cout << "Index: " << inputParameters.device << endl;
    cout << "Max input channels: " << info->maxInputChannels << endl;
    cout << "Max output channels: " << info->maxOutputChannels << endl;
    cout << "Device name: " << info->name << endl;


    inputParameters.channelCount = 1;
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    return 0;
}


/// This is the callback function used by portaudio to process any incoming audio.
int Receiver::processBuffer(const void *inputBuffer, void *outputBuffer, unsigned long samplesPerBuffer,
                            const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *data
) {

    ReceiveConfig *config = (ReceiveConfig *) data;
    const float *samples = (float *) inputBuffer;


    for (int i = 0; i < samplesPerBuffer; i++) {
        float index = (float) ((float) asin(samples[i]) * ProtocolConstants::TABLE_SIZE) / (M_PI * 2);
        config->lastPhase = index;
    }

    return paContinue;

}


void Receiver::receive() {

    const int samplesPerBuffer = ProtocolConstants::SAMPLES_PER_BYTE / ProtocolConstants::BUFFERS_PER_BYTE;
    cout << samplesPerBuffer << endl;
    error = Pa_OpenStream(
            &stream,
            &inputParameters,
            NULL,
            ProtocolConstants::SAMPLE_RATE,
            samplesPerBuffer,
            paClipOff,
            processBuffer,
            &config
    );
    cout << error << endl;

    error = Pa_StartStream(stream);
    cout << error << endl;

    float lastPhase = 0;
    float phaseStep = 0;
    while (Pa_IsStreamActive(stream)) {
        if (config.lastPhase - lastPhase != phaseStep) {
            phaseStep = config.lastPhase - lastPhase; // THIS WON"T WORK - SAMPLES DEPEND ON AMPLITUDE -> EASILY INTERFERED!!
            cout << phaseStep << endl;
        }
    }


}

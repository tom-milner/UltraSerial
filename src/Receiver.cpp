//
// Created by Tom Milner on 10/05/2020.
//

#include "Receiver.h"

#include <fftw3.h>
#include <portaudio.h>
#include <cstdlib>
#include "Config.h"
#include <string>
#include "iostream"


using std::cout;
using std::cerr;
using std::endl;
using std::string;

/// Initialise the receiver.
int Receiver::init(float ctrlFreq) {

    config.inSignal = config.bufferCounter = 0 ;

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
    const float * samples = (float *) inputBuffer;

    /// If we haven't yet detected the start byte, or if it is time to read the next char, FFT the buffer.
    if(!config->inSignal || config->bufferCounter ==  ProtocolConstants::BUFFERS_PER_CELL){
        fftw_complex * fftBuffer = (fftw_complex *) fftw_malloc(samplesPerBuffer * sizeof(fftw_complex));
        /// Read the samples into the FFT buffer.
        for(int i = 0 ; i < samplesPerBuffer; i++){
            fftBuffer[i][0] = samples[i];
            fftBuffer[i][1] = 0;
        }


    }else{

    }
    config->bufferCounter++;
    return paContinue;

}

void Receiver::receive() {

    const int samplesPerBuffer = (ProtocolConstants::SAMPLES_PER_BYTE +
                                 ProtocolConstants::SAMPLES_PER_BRIDGE) / ProtocolConstants::BUFFERS_PER_CELL;
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

//    fftw_plan plan = fftw_plan_dft_1d(ProtocolConstants::SAMPLES_PER_BUFFER, config.recordedSamples);

    error = Pa_StartStream(stream);
    cout << error << endl;

    while (Pa_IsStreamActive(stream)) {

    }


}

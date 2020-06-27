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
#include "RingBuffer.h"
#include <fftw3.h>
#include <chrono>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ofstream;
using namespace std::chrono;


/// Initialise the receiver.
int Receiver::init(float ctrlFreq, uint8_t encoding) {

    cout << "Initializing..." << endl;
    error = Pa_Initialize();
    if (error) return error;
    cout << error << endl;;

    /// Use the default input device.
    inputParameters.device = Pa_GetDefaultInputDevice();
    if (inputParameters.device == 0) {
        cout << "No input device found" << endl;
        return 1;
    }
    receiveConfig.baseFreq = ctrlFreq;
    receiveConfig.encoding = encoding;

    cout << inputParameters.device << endl;

    auto info = Pa_GetDeviceInfo(inputParameters.device);
    cout << "Index: " << inputParameters.device << endl;
    cout << "Max input channels: " << info->maxInputChannels << endl;
    cout << "Max output channels: " << info->maxOutputChannels << endl;
    cout << "Device name: " << info->name << endl;
    cout << "Control Frequency: " << receiveConfig.baseFreq << endl;


    inputParameters.channelCount = 1; // Mono audio.
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    return 0;
}


/// This is the callback function used by portaudio to process any incoming audio. It HAS to have all the parameters listed, even if they aren't used!
int Receiver::processBuffer(const void *inputBuffer, void *outputBuffer, unsigned long samplesPerBuffer,
                            const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *data
) {

    ReceiveConfig *receiveConfig = (ReceiveConfig *) data;
    const float *samples = (float *) inputBuffer;


    /// Read samples into ring buffer.
    for (int i = 0; i < ProtocolConstants::SAMPLES_PER_BUFFER; i++) {
        if (receiveConfig->inDataStream) {
            receiveConfig->sampleCount++;
        }
        receiveConfig->rb->put(samples[i]);
    }
    return paContinue;

}


void Receiver::receive() {


    cout << "Samples per buffer: " << ProtocolConstants::SAMPLES_PER_BUFFER << endl;
    cout << "Frequency Resolution: " << ProtocolConstants::SAMPLE_RATE / ProtocolConstants::SAMPLES_PER_BUFFER << endl;

    outFile.open("data.dat", std::ios::trunc); /// For debugging and graphing purposes.

    error = Pa_OpenStream(
            &stream,
            &inputParameters,
            NULL,
            ProtocolConstants::SAMPLE_RATE,
            ProtocolConstants::SAMPLES_PER_BUFFER,
            paClipOff,
            processBuffer,
            &receiveConfig
    );
    cout << error << endl;

    RingBuffer<float> ringBuffer(ProtocolConstants::SAMPLES_PER_BUFFER * 50); ///< Room for 50 buffers at once. TODO: work this out properly!!!
    receiveConfig.rb = &ringBuffer;
    error = Pa_StartStream(stream);
    cout << error << endl;

    char receivedChar, nibblePosition = 0;
    char *receivedData = (char *) malloc(8 * sizeof(char)); //TODO: work this out!!! ;
    int rDataIndex = 0;

    if (receiveConfig.encoding == NIBBLE_ENCODING) {
        double *fftBuffer = (double *) malloc(ProtocolConstants::SAMPLES_PER_BUFFER * sizeof(double));
        fftw_plan plan = nullptr;
        fftw_complex *out = (fftw_complex *) fftw_malloc(ProtocolConstants::SAMPLES_PER_BUFFER * sizeof(fftw_complex));
        plan = fftw_plan_dft_r2c_1d(ProtocolConstants::SAMPLES_PER_BUFFER, fftBuffer, out, FFTW_ESTIMATE);

        float currentSample = 0;
        while (Pa_IsStreamActive(stream)) {

            /// Add samples to fftBuffer.
            for (int i = 0; i < ProtocolConstants::SAMPLES_PER_BUFFER; i++) {
                while (!receiveConfig.rb->read(&currentSample)) {} ///< Wait until there are samples available.
                fftBuffer[i] = currentSample;
            }

            fftw_execute(plan);

            /// Compute average frequency amplitude.
            float average = 0;
            for (int i = 0; i < ProtocolConstants::SAMPLES_PER_BUFFER; i++) {

                average += out[i][0];
            }
            average = average / ProtocolConstants::SAMPLES_PER_BUFFER;

            /// Calculate the standard deviation.
            float sum = 0;
            for (int i = 0; i < ProtocolConstants::SAMPLES_PER_BUFFER; i++) {
                sum += pow(out[i][0] - average, 2);
            }
            const float stdDev = sqrt(sum / (ProtocolConstants::SAMPLES_PER_BUFFER - 1));


            /**
             * Now we process the results of the FFT.
             * We only need to look through half of the frequencies, as the results will be symmetric around the halfway point.
             * To differentiate between active frequencies and noise, we only look at frequencies that have an energy higher than 3 standard deviations above the mean.
             * This elements 99.7% of the frequencies.
             */

            int maxFreqIdx = -1;
            float maxFreqEnergy = 0;
            const float energyThreshold = average + 3 * stdDev;
            for (int i = 0; i < ProtocolConstants::SAMPLES_PER_BUFFER / 2; i++) {

                if (out[i][0] < energyThreshold) { ///< Check if the energy meets the threshold.
                    continue; /// Ignore this frequency.
                }

                // Save the frequency with the highest energy.
                if (out[i][0] >= maxFreqEnergy) {
                    maxFreqIdx = i;
                    maxFreqEnergy = out[i][0]; /// We only need to save the real component (out[i][0]), and can disregard the complex.
                }

            }
            const float foundFrequency = (ProtocolConstants::FREQUENCY_RESOLUTION) * maxFreqIdx; /// Calculate the frequency in Hz.
            outFile << foundFrequency << "    " << maxFreqEnergy << endl;
            if (foundFrequency >= receiveConfig.baseFreq) { /// Only frequencies in the valid data range.
                receivedChar = nibbleDecode(foundFrequency);
                if (nibblePosition == 0) {
                    receivedData[rDataIndex] = receivedChar;
                    nibblePosition = 1;
                } else {
                    receivedData[rDataIndex++] |= receivedChar;
                    nibblePosition = 0;
                }

            }


        }
        fftw_destroy_plan(plan);
        free(fftBuffer);
        fftw_free(out);
        free(receivedData);
    } else if (receiveConfig.encoding == BIT_ENCODING) {

        while (Pa_IsStreamActive(stream)) {
            /// TODO: Finish this!!!
        }

    }
    outFile.close();


}

char Receiver::compareFrequencies(float recFreq, float targetFreq) {


    targetFreq += receiveConfig.baseFreq;
    if (targetFreq >= recFreq && targetFreq < (recFreq + ProtocolConstants::FREQUENCY_RESOLUTION)) {
        return 1;
    }
    return 0;
}

string Receiver::byteToBinary(char byte) {
    string out;
    for (int i = 0; i < 8; i++) {
        out += (byte & (0x80 >> i)) ? "1" : "0";
    }
    return out;
}

uint8_t Receiver::nibbleDecode(float foundFrequency) {

    /// Now we convert the found frequency bin into its actual frequency value in Hz.
    if (receiveConfig.inDataStream) {

        if (receiveConfig.sampleCount >= ProtocolConstants::SAMPLES_PER_DATA) {
//                cout << std::chrono::system_clock::now().time_since_epoch().count() << endl;
//                cout << receiveConfig.sampleCount << endl;
            receiveConfig.sampleCount = 0;
            if (!compareFrequencies(foundFrequency, ProtocolConstants::START_FREQUENCY)) {
                /// Get data from the current frequency!
                if (compareFrequencies(foundFrequency, ProtocolConstants::STOP_FREQUENCY)) {
                    receiveConfig.inDataStream = 0;
                    cout << endl;
                } else {
                    uint8_t data = (int) ((foundFrequency - receiveConfig.baseFreq) / ProtocolConstants::FREQUENCY_INTERVAL);
                    cout << "Reading    " << foundFrequency << "    " << byteToBinary(data) << "    " << (int) data << endl;

                }
            }
        }

    } else {

        /// Look for start frequency.
//        cout << foundFrequency << "    " << receiveConfig.baseFreq +  ProtocolConstants::START_FREQUENCY << endl;
        if (compareFrequencies(foundFrequency, ProtocolConstants::START_FREQUENCY)) {
            receiveConfig.inDataStream = 1;
            cout << "Start!" << endl;
        }

    }

}

void Receiver::bitDecode() {

}

#include <iostream>
#include <iostream>
#include <string>
#include <unistd.h>

#include "Transmitter.h"
#include "Receiver.h"
#include "RingBuffer.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;


int transmitMode;
int controlFrequency;
string data;

void parseArgs(int argc, char **argv) {
// Get the hostname from the command line args.
    int opt;

    if (argc == 1) {
        exit(EXIT_FAILURE);
    }
    while ((opt = getopt(argc, argv, "f::td::")) != -1) { // : - Required, :: - Optional
        switch (opt) {
            case 't':
                transmitMode = 1;
                break;
            case 'f':
                controlFrequency = atoi(optarg);
                break;
            case 'd':
                data = optarg;
                break;
            default:
                exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char **argv) {
    parseArgs(argc, argv);
    if (transmitMode) {

        Transmitter transmitter;
        transmitter.init(controlFrequency);
        transmitter.transmit(const_cast<char *>(data.c_str()), data.length());
    } else {
        Receiver receiver;
        receiver.init(controlFrequency);
        cout << "Listening..." << endl;
        receiver.receive();
    }


    return 0;
}

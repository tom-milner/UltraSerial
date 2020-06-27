#include <iostream>
#include <string>
#include <unistd.h>

#include "Transmitter.h"
#include "Receiver.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;


int transmitMode;
int controlFrequency;
string data;

/**
 * Parse the command line arguments.
 * @param argc - The number of arguments.
 * @param argv - The arguments.
 */
void parseArgs(int argc, char **argv) {
    int opt;

    if (argc == 1) {
        exit(EXIT_FAILURE);
    }
    while ((opt = getopt(argc, argv, "f::t::d::")) != -1) {
        switch (opt) {
            case 't':
                transmitMode = atoi(optarg);
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

    if (data.length() > 0) { /// If no data is specified we go into receive mode.
        Transmitter transmitter;
        transmitter.init(controlFrequency, transmitMode);
        transmitter.transmit(const_cast<char *>(data.c_str()), data.length());
    } else {
        Receiver receiver;
        receiver.init(controlFrequency, transmitMode);
        cout << "Listening..." << endl;
        receiver.receive();
    }


    return 0;
}

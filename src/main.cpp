#include <iostream>
#include <iostream>
#include <string>

#include "Transmitter.h"
#include "Receiver.h"

#define TABLE_SIZE 200
#define NUM_SECONDS   2
#define SAMPLE_RATE   44100
#define FRAMES_PER_BUFFER 64
#define HIGH 1
#define LOW 0


using std::cout;
using std::cerr;
using std::endl;
using std::string;


int main() {

    Receiver receiver;
    receiver.init(880);
    receiver.receive();


//    Transmitter transmitter;
//    transmitter.init(880);
//
//    string message = "H";
//    char *data = (char *) message.c_str();
//
//    transmitter.transmit(data, message.length());


    return 0;
}

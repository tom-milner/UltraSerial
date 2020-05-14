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

//    Receiver receiver;
//    receiver.init(880);
//    cout << "Listening..." << endl;
//    receiver.receive();


    Transmitter transmitter;
    transmitter.init(220);

    uint8_t data[10]{10,20,40,30,25,15};

    transmitter.transmit(reinterpret_cast<char *>(data), 10);


    return 0;
}

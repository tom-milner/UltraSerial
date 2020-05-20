#include <iostream>
#include <iostream>
#include <string>

#include "Transmitter.h"
#include "Receiver.h"




using std::cout;
using std::cerr;
using std::endl;
using std::string;


int main() {

    Receiver receiver;
    receiver.init(880);
    cout << "Listening..." << endl;
    receiver.receive();


//    Transmitter transmitter;
//    transmitter.init(0);
//
//    string data = "Tomothy Milner";
//
//    transmitter.transmit(const_cast<char *>(data.c_str()), data.length());


    return 0;
}

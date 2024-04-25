#include "receiver.h"
#include <algorithm>
#include <sstream>
#include <cstdlib>


int main(int argc, const char * argv[])
{
    if(argc != 5 )
    {
        std::cout << "Usage: ./driver filename offset message_size packet_size" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    int offset = atoi(argv[2]);
    int message_size = atoi(argv[3]);
    int packet_size = atoi(argv[4]);


   if (packet_size > message_size)
   {
        std::cout << "Error: Packet size cannot exceed message size." << std::endl;
        return 1;
   }

    /*const std::string filename = "../message.txt";
    int packet_size = 1;
    int message_size = 50;
    int offset = 0;*/

    receiver message, receivedMessage;
    receivedMessage = message.receive_message(filename, packet_size, message_size, offset); //filename, packet_size, message_size, offset
    message.display_received_message(receivedMessage);

}
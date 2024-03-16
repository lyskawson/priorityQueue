#include "priorityQueue.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>


int main()
{
    std::string message, receivedMessage, packet;
    priorityQueue receivedPackets;
    const std::string filename = "../message.txt";
    int option;



    do {
        std::cout << "Chose one of the options: " << std::endl;
        std::cout << "Press [1] to read message from file" << std::endl;
        std::cout << "Press [2] to enter message" << std::endl;
        std::cin >> option;
        std::cin.ignore();
    } while (option != 1 && option != 2);


    if(option==1)
    {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Cannot open file: " << filename << std::endl;
        }

        for (int i = 1; file >> packet; i++)
        {
            receivedPackets.insert(packet, i);
        }
        file.close();
    }
    else if(option==2)
    {
        std::cout << "Enter message for Anna: " << std::endl;
        std::getline(std::cin, message);
        std::istringstream iss(message);

        for (int i = 1; iss >> packet; i++)
        {
            receivedPackets.insert(packet, i);
        }
    }


    std::cout << "Transferred packets in random order: " << std::endl;
    receivedPackets.randomDisplay();


    for(int i = 1; receivedPackets.getSize(); i++)
    {
        receivedMessage = receivedMessage + receivedPackets.removeMin() + " ";
        if (i % 10 == 0) {
            receivedMessage += "\n";
        }

    }

    std::cout << std::endl;
    std::cout << "Received message: " << std::endl;
    std::cout << receivedMessage << std::endl;
}
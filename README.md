
## Project description:

This program is designed to simulate a simple receiver implemented with priorityQueue  for receiving messages from a txt file. It is meant to be run from the command line, taking four arguments: filename, offset, message_size, and packet_size. The program will read a message from the specified file, starting from the given offset, and display the received message. 

## Project Structure:

* ***main.cpp**: Contains the main function of the program. 
* **runtimes.cpp**: This file contains functions related to calculating runtimes needed for calculating computational complexity
* **receiver.cpp**: Implementation file for the receiver class
* **receiver.h**: Header file declaring the receiver class 
* **receiver.o**: Object file generated after compiling the receiver.cpp file
* **driver**: Executable program 

## Compiling Project

To compile the project, navigate to the project directory and use the following command:
**g++ receiver.cpp -c**
**g++ main.cpp receiver.o -o driver_zad3**

## Usage

To execute the driver program:
**./driver_zad3 filename offset message_size packet_size**
- **filename**: The name of the file containing the message
- **offset**: The starting position in the file from where to begin reading the message
- **message_size**: The total size of the message to be read
- **packet_size**: The size of each packet to be read from the file

## Error Handling

The program includes basic error handling. If the number of arguments provided is not equal to 5, it will display a usage message. Additionally, if the packet size exceeds the message size, an error message will be displayed.

## Author 
This program was written by Aleksander Lyskawa.


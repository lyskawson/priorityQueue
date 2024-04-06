#ifndef PROJECT1_RECEIVER_H
#define PROJECT1_RECEIVER_H
#include <iostream>
#include <random>
#include <fstream>
#include <algorithm>

struct Node
{
    std::string data;
    int seqNum;
    Node* prev;
    Node* next;
    Node() {}
    Node(const std::string& data, const int seqNum, Node* prev, Node* next);
};

class receiver
{
private:
    Node* head;
    Node* tail;
    int size;
    void insert(const std::string& data, int seqNum);
    const std::string getMin() const;
    const std::string removeMin();
    int getSize() const;

public:
    receiver();
    receiver receive_message(const std::string filename,  int packet_size, int message_size, int offset);
    void display_received_message(receiver receivedPackets);
};

#endif

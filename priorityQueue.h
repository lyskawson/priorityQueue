#ifndef PROJECT1_PRIORITYQUEUE_H
#define PROJECT1_PRIORITYQUEUE_H
#include<iostream>

struct Node
{
    std::string data;
    int priority;
    Node() {}
    Node(const std::string& data, const int priority);
};

class priorityQueue
{
    static const int MAX_CAPACITY = 10000;
    Node elements[MAX_CAPACITY];
    int size;


public:
    priorityQueue();
    void insert(const std::string& data, int priority);
    const std::string getMin() const;
    const std::string removeMin();
    int getSize() const;
    void display() const;
    void randomDisplay() const;
};

#endif

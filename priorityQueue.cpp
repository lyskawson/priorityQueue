#include"priorityQueue.h"
#include <iostream>
#include <random>

Node::Node(const std::string& data, const int priority) : data(data), priority(priority)
{

}

priorityQueue::priorityQueue() : size(0)
{

}

void priorityQueue::insert(const std::string &data, int priority)
{
    if (size == MAX_CAPACITY)
        throw std::out_of_range("Queue is full. Cannot add new elements..");

    int i = size;
    while (i > 0 && elements[i - 1].priority > priority)
    {
        elements[i] = elements[i - 1];
        --i;
    }

    elements[i] = Node(data, priority);
    ++size;

}

const std::string priorityQueue::getMin() const
{
    return elements[0].data;
}

const std::string priorityQueue::removeMin()
{
    std::string minData = getMin();

    for(int i = 1; i < size; ++i)
    {
        elements[i-1] = elements[i];
    }
    --size;
    return minData;
}

int priorityQueue::getSize() const
{
    return size;
}



void priorityQueue::display() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "[" << elements[i].priority << "]"  <<  elements[i].data  << " ";
    }
    std::cout << std::endl;
}

void priorityQueue::randomDisplay() const
{

    Node shuffledElements[MAX_CAPACITY];
    std::copy(elements, elements + size, shuffledElements);


    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(shuffledElements, shuffledElements + size, std::default_random_engine(seed)); // ze strony https://cplusplus.com/reference/algorithm/shuffle/


    for (int i = 0; i < size; ++i)
    {
        std::cout << "[" << shuffledElements[i].priority << "]" << shuffledElements[i].data << " ";
        if (i % 10 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;

}



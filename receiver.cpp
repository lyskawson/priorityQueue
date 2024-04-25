#include"receiver.h"

Node::Node(const std::string& data, const int seqNum, Node* prev, Node* next) : data(data), seqNum(seqNum), prev(prev), next(next)
{

}

receiver::receiver() : head(nullptr), tail(nullptr), size(0)
{

}

void receiver::insert(const std::string& data, int seqNum)
{
    Node* newNode = new Node(data, seqNum, nullptr, nullptr);

    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        Node* current = head;
        // find position for given sequence number
        while (current && seqNum > current -> seqNum)
        {
            current = current -> prev;
        }
        // for node inserted at the end
        if (!current)
        {
            tail -> prev = newNode;
            newNode -> next = tail;
            tail = newNode;
        }
        else
        {
            newNode -> next = current->next;
            newNode -> prev = current;

            if (newNode -> next)
            {
                newNode -> next -> prev = newNode;
            }
            newNode -> prev -> next = newNode;

            if (head == tail || seqNum <= head -> seqNum)
            {
                head = newNode;
            }
        }
    }

    size++;
}


const std::string receiver::removeMin()
{
    if (!head)
    {
        throw std::runtime_error("Cannot remove element. List is empty.");
    }

    Node* temp = head;
    std::string data = temp->data;
    head = head -> prev;

    if (head)
    {
        head -> next = nullptr;
    }

    delete temp;
    size--;

    return data;
}

int receiver::getSize() const
{
    return size;
}

receiver receiver::receive_message(const std::string filename, int packet_size, int message_size, int offset)
{
    std::ifstream file(filename);
    receiver receivedPackets;

    if (!file.is_open())
    {
        std::cout << "Failed to open file: " << filename << std::endl;
        return receivedPackets;
    }

    std::string word;
    int packetCount = 0;
    std::string packetContents = "";
    int wordsRead = 0; // number of words read
    int wordsInserted = 0; // number of words inserted in the current message
    int wordsSkipped = 0; // number of words skipped

    while (file >> word)
    {
        // skip words based on the offset
        if (wordsSkipped < offset)
        {
            wordsSkipped++;
            continue;
        }

        if (wordsInserted >= message_size)
            break;


        packetContents = packetContents + word + " ";

        wordsRead++;
        wordsInserted++;

        // if the packet size is reached
        if (wordsRead == packet_size)
        {
            packetCount++;
            receivedPackets.insert(packetContents, packetCount);
            packetContents = ""; // reset packet contents
            wordsRead = 0; // reset the read words
        }
    }

    // for remaining words that are not forming a complete packet
    if (!packetContents.empty())
    {
        packetCount++;
        receivedPackets.insert(packetContents, packetCount);
    }
    file.close();

    return receivedPackets;
}

void receiver::display_received_message(receiver receivedPackets)
{
    std::string receivedMessage;
    for (int i = 1; receivedPackets.getSize(); i++)
    {
        receivedMessage = receivedMessage + receivedPackets.removeMin();
    }
    std::cout << std::endl;
    std::cout << "Received message: " << std::endl;
    std::cout << receivedMessage << std::endl;
}







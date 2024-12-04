#include <iostream>
#include <cstdlib>
using namespace std;

struct QueueNode
{
    char data;
    QueueNode *link;
};

typedef QueueNode *QueueNodePtr;

class Queue
{
public:
    Queue();
    Queue(const Queue &aQueue);
    ~Queue();
    void add(char item);
    char remove();
    bool empty() const;

private:
    QueueNodePtr front;
    QueueNodePtr back;
};

int main()
{
    return 0;
}

Queue::Queue() : front(nullptr), back(nullptr) {}

Queue::Queue(const Queue &aQueue) // copy constructor exercise 12
{
    if (aQueue.front == nullptr || aQueue.back == nullptr)
    {
        front = nullptr;
        back = nullptr;
    }
    else
    {
        QueueNodePtr temp = aQueue.front;
        QueueNodePtr end = new QueueNode;
        end->data = temp->data;
        front = end;

        temp = temp->link;
        while (temp != nullptr)
        {
            end->link = new QueueNode;
            end = end->link;
            end->data = temp->data;

            temp = temp->link;
        }
        back = end;
        end->link = nullptr;
    }
}

Queue::~Queue() // destructor exercise 13
{
    char next;
    while (!empty())
    {
        next = remove();
    }
}

bool Queue::empty() const
{
    return (back == nullptr);
}

void Queue::add(char item)
{
    if (empty())
    {
        front = new QueueNode;
        front->data = item;
        front->link = nullptr;
        back = front;
    }
    else
    {
        QueueNodePtr temp_ptr;
        temp_ptr = new QueueNode;
        temp_ptr->data = item;
        temp_ptr->link = nullptr;
        back->link = temp_ptr;
        back = temp_ptr;
    }
}

char Queue::remove()
{
    if (empty())
    {
        cout << "Error: Removing an item from an empty queue.\n";
        exit(1);
    }
    char result = front->data;
    QueueNodePtr discard;
    discard = front;
    front = front->link;

    if (front == nullptr)
    {
        back = nullptr;
    }
    delete discard;

    return result;
}
#include <iostream>
using namespace std;
struct StackFrame
{
    char data;
    StackFrame *link;
};

typedef StackFrame *StackFramePtr;

class Stack
{
public:
    Stack();
    Stack(const Stack &a_stack); // copy constructor
    ~Stack();
    void push(char the_symbol);
    char pop();
    bool empty() const;

private:
    StackFramePtr top;
};

int main()
{
    return 0;
}

Stack::Stack() : top(nullptr) {}

Stack::Stack(const Stack &a_stack) // exercise 11
{
    if (a_stack.top == nullptr)
    {
        top = nullptr;
    }
    else
    {
        StackFramePtr temp = a_stack.top;
        StackFramePtr end = new StackFrame;
        end->data = temp->data;
        top = end;

        temp = temp->link;
        while (temp != nullptr)
        {
            end->link = new StackFrame;
            end = end->link;
            end->data = temp->data;

            temp = temp->link;
        }
        end->link = nullptr;
    }
}

void Stack::push(char the_symbol) // exercise 10
{
    StackFramePtr current = new StackFrame;
    current->data = the_symbol;
    current->link = top;
    top = current;
}

Stack::~Stack()
{
    char next;
    while (!empty())
    {
        next = pop();
    }
}

bool Stack::empty() const
{
    return (top == nullptr);
}

char Stack::pop()
{
    if (empty())
    {
        cout << "Error: popping an empty stack.\n";
        exit(1);
    }
    char result = top->data;

    StackFramePtr temp_ptr{top};
    top = top->link;

    delete temp_ptr;

    return result;
}
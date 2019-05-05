#include "stack.h"

stack::stack()
{
    index = -1;
    return;
}

void stack::push(int val)
{
    ++index;
    values[index] = val;
    return;
}

int stack::pop()
{
    int temp;
    if(isEmpty())
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    temp = values[index];
    --index;

    return temp;    
}

int stack::peek()
{
    if(isEmpty())
    {
        cout << "Stack is empty" << endl;
    }

    return values[index];
}

bool stack::isEmpty()
{
    return index == -1;
}

#include <iostream>
using namespace std;

class stack 
{
    public:
        stack();
        void push(int);
        int pop();
        int peek();
        bool isEmpty();
    private:
        int values[100];
        int index;
};

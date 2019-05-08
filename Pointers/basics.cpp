#include <iostream>
using namespace std;

int main(void)
{
    int * pointer; //declaring the pointer
    pointer = new int; // allocating memory
    *pointer = 5; // setting a value at the memory address, must dereferene the pointer
    cout << pointer // not dereferenced, prints memory address
         << " : " 
         << *pointer // dereferenced, prints value
         << endl; 

    int var = 22;
    int *p = &var;
    cout << *p << endl;
    *p = 40;
    cout << var << endl;

    delete pointer; // make sure to deallocate your pointers
    return 0;
}

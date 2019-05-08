// Dynamically sizing strings

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    char buffer[100];
    char *name;

    cout << "Enter your name: ";
    cin.get(buffer, 100, '\n');
    name = new char[strlen(buffer)]; // too small, will leave out null terminator
    strcpy(name, buffer);
    cout << "Hello, " << name << endl;

    delete [] name;
    return 0;
}

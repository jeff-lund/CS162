#include <iostream>
using namespace std;

int main(void)
{
    char name[] = "Jonah";
    char *ptr = name;
    cout << ptr << endl;      // Jonah
    cout << *ptr << endl;     // J
    cout << *(ptr++) << endl; // J
    cout << *(++ptr) << endl; // a
    cout << ++(*ptr) << endl; // n
    cout << ++ptr << endl;    // ah
    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    char str[] = "abcdefghijk";
    char *ptr = str;
    /*
    int i = 0;
    while(ptr)
    {
        cout << ptr++ << endl;
        if(++i > 100)
            break;
    }
    cout << endl;
    */
    while(*ptr)
    {
        //cout << *ptr++;
        cout << ptr++ << endl;
    }
    cout << endl;
    return 0;
}

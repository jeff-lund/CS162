#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    char word[] = "Bringing home the rain";
    char *ptr;
    int length;
    // find length of the phrase    
    length = strlen(word);
    // moving half the length will bring us to the middle
    length /= 2;
    // start the pointer at the beginning of the phrase
    ptr = word;
    // advance the pointer until halfway through
    for(int i = 0; i < length; ++i)
       ++ptr;
    // printing the pointer will print starting at the point until it reachs '\0'
    cout << ptr << endl; 

    return 0;
}

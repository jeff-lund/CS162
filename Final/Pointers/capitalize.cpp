#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Task: Capitalize all letters in a string using a pointer

int main(void)
{
    char word[] = "Bird is the word.";
    char *ptr;
    ptr = word;

    while(*ptr != '\0') // traverse until we find the null terminator
    {
        // remember to dereference
        *ptr = toupper(*ptr);
        ++ptr;
    }
    // ptr now points at the end of the word, to print use initial variable name
    cout << word << endl;        
    return 0;
}

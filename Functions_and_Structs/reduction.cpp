#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// If two characters are the same letter but different cases 
// eliminate them from the string
// print out the final reduced string

int main(void) 
{
    char str[] = "dabAcCaCBAcCcaDA";
    char reduced[] = "dabCBAcaDA";
    cout << "Original string: " << str << endl;
    for(int i = 0; i < strlen(str) - 1; ++i)
    {
        // check if adjacent characters match the elimination pattern
        if(tolower(str[i]) == tolower(str[i+1]) 
           && ((isupper(str[i]) && islower(str[i+1]))
           || (islower(str[i]) && isupper(str[i+1]))))
           {
                // overwrite characters to be eliminated
                for(int j = i; j < strlen(str); ++j)
                {
                    str[j] = str[j+2];
                }
                // change index to check one character back
                if(i == 0) 
                {
                    i = -1;
                }
                else
                {
                    i -= 2;
                }
           }
    }
    cout << "Reduced string: " << str << endl;
    if(strcmp(str, reduced) == 0)
    {
        cout << "reduction was sucessful" << endl;
    }
    else
    {
        cout << "error in reduction" << endl;
    }
    return 0;
}

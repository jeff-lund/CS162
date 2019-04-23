#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// If two characters are the same letter but different cases 
// eliminate them from the string
// print out the final reduced string

// for two characters to match they must be of the same letter
// and different cases
bool match(char c1, char c2)
{
    // not the same letter
    if(tolower(c1) != tolower(c2))
    {
        return false;
    }
    // both uppercase
    if(isupper(c1) && isupper(c2))
    {
        return false;
    }
    // both lowercase
    if(islower(c1) && islower(c2))
    {
        return false;
    }
    // if none of the conditions above are matched 
    // then the characters match and should be reduced
    return true;
}


bool match2(char c1, char c2) {
    if(tolower(c1) != tolower(c2))
        return false;
    if(isupper(c1) && isupper(c2))
        return false;
    if(islower(c1) && islower(c2))
        return false;
    return true;
}



int main(void) 
{
    char str[] = "dabAcCaCBAcCcaDA";
    int length = strlen(str);
    char buffer[length]; // buffer to hold the new string while it is processed
    char reduced[] = "dabCBAcaDA";
    bool skip = false; // skips the next character in the string if true
    bool reduction; // marks if the working string has been reduced
    int index; // index of second string

    cout << "Original string: " << str << endl;
    do 
    {
        reduction = false; 
        length = strlen(str);
        index = 0;
        for(int i = 0; i < length - 1; ++i)
        {
            if(skip) 
            {
                skip = false;
            }
            else
            {
                // check if adjacent characters match the elimination pattern
                if(match(str[i], str[i+1]))
                {
                    skip = true; // skip over the next character
                    reduction = true; // the string has been reduced
                }
                else
                {
                    buffer[index] = str[i]; // copy char to buffer string
                    ++index;
                }   
            }
        }
        
        if(!skip)
        {
            buffer[index++] = str[length - 1];
        }
        buffer[index] = '\0';
        strcpy(str, buffer); // copy working string into orginal to reduce again
    } while(reduction);

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

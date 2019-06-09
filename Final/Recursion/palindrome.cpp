#include <iostream>
using namespace std;

// Task: use a recursive function to find if a number is a palindrome
// [1, 5, 10, 10, 5, 1] <-- is a palindrome
// [1, 2, 3, 4, 5] <-- is not a palindrome

bool palindrome(int arr[], int start, int end)
{
    // base case start == end or start passes end (depends if even or odd)
    if(start >= end)
        return true;
    // and (&&) together the recursive comparisons for the pairs 
    return arr[start] == arr[end] && palindrome(arr, start + 1, end - 1);
}

int main(void)
{
    int even[] = {1, 5, 10, 10, 5, 1};
    int odd[] = {1, 5, 7, 5, 1};
    int bad[] = {1, 2, 3, 4, 5};
    bool t[3];
    
    t[0] = palindrome(even, 0, 5);
    t[1] = palindrome(odd, 0, 4);
    t[2] = palindrome(bad, 0, 4);

    for(int i = 0; i < 3; ++i)
    {
        if(t[i])
            cout << "This is a palindrome" << endl;
        else
            cout << "This is not a palindrome" << endl;
    }

    return 0;
}

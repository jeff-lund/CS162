#include <iostream>
using namespace std;

// Task: Display element in an array with a pointer

int main(void)
{
    int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ptr;
    // numbers is already a memory address so we do not need the address (&) operator
    // this sets ptr to point to the first element of numbers
    ptr = numbers;
    for(int i = 0; i < 10; ++i)
    {
        // remember to dereference the pointer to access the element and not address
        cout << *ptr << " ";
        ++ptr;
    }
    cout << endl;
    return 0;
}

#include <iostream>
using namespace std;

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int *ptr = arr; // assigns ptr to the beginning of the array
    for(int i = 0; i < 5; ++i, ++ptr)    
        cout << "ptr = " << ptr << " | *ptr = " << *ptr << endl;

    return 0;
}

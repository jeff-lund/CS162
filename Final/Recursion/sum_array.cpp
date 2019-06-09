#include <iostream>
using namespace std;

// Task: Sum the positive numbers from an array

// recrusive positive sum
int pos_sum(int arr[], int length)
{
    // base case, empty array sums to 0, no recursive call
    if(length == 0)
        return 0; 
    // if the element at the end is positive include it and recurse
    if(arr[length - 1] > 0)
        return arr[length - 1] + pos_sum(arr, length - 1);
    // otherwise recurse with the current value
    else
       return pos_sum(arr, length - 1); 
}

int main(void)
{
    // should sum to 15
    int arr[] = {1, 2, -5, 3, 4, -12, 5, -99};
    int length = 8;
    int s;

    s = pos_sum(arr, length);
    cout << s << endl;

    return 0;
}

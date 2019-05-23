#include <iostream>
using namespace std;

int fib(int n)
{
    if(n == 0) // base case
        return 0; 
    if(n == 1) // base case
        return 1;
    return fib(n - 1) + fib(n - 2); // recursive calls
}

int main(void)
{   
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The " << n << " fibonacci number is " << fib(n) << endl;
    return 0;
}

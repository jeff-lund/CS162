#include "stack.h"
using namespace std;

void menu()
{
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cout << "4. isEmpty" << endl;
    cout << "5. Quit" << endl;
}

int main(void)
{
    int val, choice;
    bool empty, loop = true;
    stack my_stack;

    while(loop)
    {
        menu();
        cin >> choice;
        if(choice == 1) {
            cout << "Enter a value: " << endl;
            cin >> val;
            my_stack.push(val);
        }
        else if(choice == 2) {
            val = my_stack.pop();
            cout << "Value: " << val << endl;
        }
        else if(choice == 3) {
            val = my_stack.peek();
            cout << "Value: " << val << endl;
        }
        else if(choice == 4) {
            empty = my_stack.isEmpty();
            if(empty)
                cout << "The stack is empty" << endl;
            else
                cout << "The stack is not empty" << endl;
        }
        else if(choice == 5)
            loop = false;
        cout << endl;
    }
    return 0;
}

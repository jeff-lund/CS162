#include <iostream>
using namespace std;

void strange(void);

int main(){
    cout <<"Please enter a string" <<endl;
    strange();
    cout <<endl;
    return 0;
}

void strange(void) {
    char ch;
    cin.get(ch);
    if (!cin.eof() && ch != '\n'){
        strange();
        cout <<ch;
    }
}

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout;
    char buffer[100];
    char cont;
    bool loop = true;

    fout.open("log.txt", ios::app);
    fout << "*********************New log entry**************************\n";

    while(loop)
    {
        cout << "Enter phrase to log: ";
        cin.get(buffer, 100, '\n');
        
        cin.ignore(100, '\n');
        fout << buffer << '\n';
        
        cout << "Continue (y/n)? ";
        cin >> cont;
        cin.ignore(100, '\n');
        
        if(cont == 'n') 
           loop = false; 
    }
    fout.close();

    return 0;
}

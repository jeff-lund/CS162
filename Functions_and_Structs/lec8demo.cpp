/* ***************************************************
 * Demo from page 10 of handwritten slide
 * for external files
 * **************************************************/

#include <iostream> 
#include <fstream>

using namespace std;

const int SIZE = 100;

struct person 
{
    char name[SIZE];
    int age;
    int year;
};

int main(void)
{
    char filename[SIZE];
    char name[SIZE]; 
    int age;
    int year;

    cout << "Enter a file to read: ";
    cin >> filename;
    cin.ignore(100, '\n');

    ifstream fin; // file variable
    fin.open(filename);
    if(fin) // are we connected?
    {
        fin.get(name, SIZE, '\t');
        fin.ignore(100, '\t'); // <-- Notice new delimiter
        while(!fin.eof()) // while we still have data
        {
            fin >> age;
            fin.ignore();
            fin >> year;
            fin.ignore(100, '\n');

            // use the data here
            cout << name << " " << age << " years old, born in " 
                << year << endl;      
            // Now prime the pump
            // is there another?
            fin.get(name, SIZE, '\t'); // <- will trip the eof flag
            fin.ignore(100, '\t');     //    if there is no more data    
        }
    }
    fin.close();
    return 0;
}

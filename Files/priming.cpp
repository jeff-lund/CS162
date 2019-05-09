/*************************************************
* Demo program to show the need to prime the pump
* and ensure EOF status
* Use sample file: dogs.txt
***************************************************/


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct dog
{
    char name[20];
    char breed[20];
    int age;
};

// Reading file into struct without properly setting EOF flag
void read_bad(dog my_dogs[])
{
    char filename[20];
    int i = 0;
    ifstream fin;

    cout << "Enter the file name: ";
    cin.get(filename, 20, '\n');
    cin.ignore(100, '\n');

    fin.open(filename);
    if(!fin) // check to make sure we have a connection to input file stream
    {
        cout << "File not found!" << endl;
        return;
    }

    while(!fin.eof()) // read until you reach end of file
    {
        fin.get(my_dogs[i].name, 20, '|'); //read dogs name
        fin.ignore();
        fin.get(my_dogs[i].breed, 20, '|'); // read dogs breed
        fin.ignore();
        fin >> my_dogs[i].age; // read dogs age
        fin.ignore(100, '\n');
        ++i; // move to next dog in struct
    }
    fin.close();

    for(int j = 0; j < i; ++j)
    {
        cout << my_dogs[j].name << ", "
             << my_dogs[j].breed << ", "
             << my_dogs[j].age << " years old" <<endl;
    }

    return;
}

// Reading in a file to a struct with priming
void read_good(dog my_dogs[])
{
    char filename[20];
    int i = 0;
    ifstream fin;

    cout << "Enter the file name: ";
    cin.get(filename, 20, '\n');
    cin.ignore(100, '\n');

    fin.open(filename);
    if(!fin) // check to make sure we have a connection to input file stream
    {
        cout << "File not found!" << endl;
        return;
    }

    fin.get(my_dogs[i].name, 20, '|'); // first read to set flag
    fin.ignore();

    while(!fin.eof()) // read until you reach end of file
    {
        fin.get(my_dogs[i].breed, 20, '|'); // read dogs breed
        fin.ignore();
        fin >> my_dogs[i].age; // read dogs age
        fin.ignore(100, '\n');
        fin.get(my_dogs[++i].name, 20, '|'); // priming the pump
        fin.ignore();
    }
    fin.close();

    for(int j = 0; j < i; ++j)
    {
        cout << my_dogs[j].name << ", "
             << my_dogs[j].breed << ", "
             << my_dogs[j].age << " years old" <<endl;
    }

    return;
}

int main(void)
{
    dog lots_of_dogs[100];
    read_bad(lots_of_dogs);
    read_good(lots_of_dogs);

    return 0;
}

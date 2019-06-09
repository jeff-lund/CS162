#include <iostream>
#include <cstring>
using namespace std;

// Sizing strings just right

struct book {
    char * author;
    char * title;
    double * price;
};

book read_book(void)
{
    book a_book;
    char buffer[500];
    int length;
        
    cout << "Enter the title: ";
    // read into large buffer
    cin.get(buffer, 500, '\n');
    cin.ignore();
    // find size of buffer
    length = strlen(buffer);
    // dynamically allocate size + 1. Why +1?  
    a_book.title = new char[length + 1];
    // copy data over the the dynamically allocated string
    strcpy(a_book.title, buffer);

    cout << "Enter the author: ";
    cin.get(buffer, 500, '\n');
    cin.ignore();
    length = strlen(buffer);
    a_book.author = new char[length + 1];
    strcpy(a_book.author, buffer);

    cout << "Enter the price: ";
    a_book.price = new double;
    cin >> *a_book.price;
    cin.ignore(100, '\n');

    return a_book;
}

int main(void)
{
    book b;
    b = read_book();
    cout << b.title << 
        " by " << b.author << 
        " is on sale now for " << *b.price << "." << endl;

    // how would you deallocate memory here?
    return 0;
}

/* 
* Example of using pointers and dynamic memory 
* to allocate arrays
*/

#include <iostream>
using namespace std;

int main(void)
{
    int num_students; //total number of students in the class
    double *grades;
    double sum = 0;

    cout << "Enter the number of students in the class: ";
    cin >> num_students;
    grades = new double[num_students]; // array is dynamically allocated at runtime so it
                                       // is exactly big enough for the number of students

    for(int i = 0; i < num_students; ++i)
    {
        cout << "Enter a grade: ";
        cin >> grades[i];
    }

    for(int i = 0; i < num_students; ++i)
        sum += grades[i];

    cout << "Class average: " << sum / num_students << endl;

    delete [] grades; // deallocate a dynamically allocated array
    return 0;
}

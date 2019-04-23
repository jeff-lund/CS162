/**************************************
 * Manage grades for a class
 * Bad monolithic version
 **************************************/

#include <iostream>
using namespace std;

const int SIZE = 100;

int main(void) {
    int num_students = 0; // initially no students in the gradebook
    int menu_choice; // user input var
    int id; // holds user input for student id
    // parallel arrays to hold information for each individual student
    int student_id[SIZE]; // array of unique student ids
    double midterm[SIZE] = {0}; // midterm scores
    double final_[SIZE] = {0}; // finals score
    double program[SIZE] = {0}; // program score
    char repeat = 'y';
    char choice; // user input var
    bool found; // flag if user id found

    while(repeat != 'n')
    {
        cout << "1. Add a student" << endl;
        cout << "2. Grade an item" << endl;
        cout << "3. Get class average for an item" << endl;
        cout << "4. Adjust a students grade" << endl;
        cout << "5. View student information" << endl;
        cout << "6. Compute final grades" << endl;
        cout << "7. Exit Program" << endl;
        cout << "Enter an option: " << endl;
        cin >> menu_choice;
        // add a student
        if(menu_choice == 1)
        {
           cout << "Enter the id number: ";
           cin >> id;
           student_id[num_students++] = id;
        }
        // add a grade item
        else if(menu_choice == 2)
        {
            cout << "This totally isn't implemented yet!" << endl;
        }
        // class average
        else if(menu_choice == 3)
        {
            cout << "This totally isn't implemented yet!" << endl;
        }
        // adjust individual grade
        else if(menu_choice == 4)
        {
            cout << "This totally isn't implemented yet!" << endl;
        }
        // view student
        else if(menu_choice == 5)
        {
            cout << "View (i)ndividual student or (a)ll students? ";
            cin >> choice;
            if(choice == 'i')
            {
                cout << "Enter id number: ";
                cin >> id;
                found = false;
                for(int i = 0; i < num_students; ++i)
                {
                    if(student_id[i] == id)
                    {
                        found = true;
                        cout << "Student id: " << student_id[i] << endl;
                        cout << "Midterm Grade: " << midterm[i] << endl;
                        cout << "Final Grade: " << final_[i] << endl;
                        cout << "Program Grade: " << program[i] << endl;
                        cout << "************************************************************" << endl;
                    }
                }
                if(!found)
                {
                    cout << "Invalid id" << endl;
                }
            }
            else if(choice == 'a')
            {
                for(int i = 0; i < num_students; ++i)
                {
                    cout << "Student id: " << student_id[i] << endl;
                    cout << "Midterm Grade: " << midterm[i] << endl;
                    cout << "Final Grade: " << final_[i] << endl;
                    cout << "Program Grade: " << program[i] << endl;
                    cout << "************************************************************" << endl;
                }
                cout << endl;
            }
        }
        // final grades
        else if(menu_choice == 6)
        {
            cout << "This totally isn't implemented yet!" << endl;
        }
        else if(menu_choice == 7)
        {
          repeat = 'n';
        }
        else
        {
            cout << "Invalid selection." << endl;
        }
    }

    cout << "Thanks for using the gradebook!" << endl;
    return 0;
}

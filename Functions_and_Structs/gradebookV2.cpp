/**************************************
 * Manage grades for a class
 * Better version, code is broken up into functions
 **************************************/

#include <iostream>
using namespace std;

const int SIZE = 100;

struct student {
  int id; // id is assumed to be positive
  char name[SIZE];
  double midterm_grade;
  double final_grade;
  double program_grade;
};

void menu_print(void)
{
  cout << "1. Add a student" << endl;
  cout << "2. Grade an item" << endl;
  cout << "3. Get class average for an item" << endl;
  cout << "4. Adjust a students grade" << endl;
  cout << "5. View student information" << endl;
  cout << "6. Compute final grades" << endl;
  cout << "7. Quit" << endl;
  cout << "Enter an option: " << endl;
  return;
}

void grade_program(student& s)
{
    cout << "Enter a program grade for " << s.name << ": ";
    cin >> s.program_grade;
    cin.ignore();
    return;
}

void grade_midterm(student& s)
{
  cout << "Enter a midterm grade for " << s.name << ": ";
  cin >> s.midterm_grade;
  cin.ignore();
  return;
}

void grade_final(student& s)
{
  cout << "Enter a final grade for " << s.name << ": ";
  cin >> s.final_grade;
  cin.ignore();
  return;
}

int find_student(student students[], int length, int id)
{
  int index = -1;
  for(int i = 0; i < length; ++i)
  {
    if(students[i].id == id)
    {
      index = i;
    }
  }
  return index;
}

void student_print(student& s)
{
  cout << "Name: " << s.name << endl;
  cout << "Student id: " << s.id << endl;
  cout << "Midterm Grade: " << s.midterm_grade << endl;
  cout << "Final Grade: " << s.final_grade << endl;
  cout << "Program Grade: " << s.program_grade << endl;
  cout << "****************************************************" << endl;
  return;
}

void add_student(student& s)
{
  cout << "Enter the students name: ";
  cin.get(s.name, 100, '\n');
  cin.ignore();
  cout << "Enter the student id number: ";
  cin >> s.id;
  cin.ignore();
  cout << s.name << " added to the gradebook" << endl;
  s.final_grade = 0; // initialze all grades to zero for a new student
  s.midterm_grade = 0;
  s.program_grade = 0;

  return;
}

void view_students(student students[], int length)
{
  char choice;
  int id;
  int index;

  cout << "View (i)ndividual student or (a)ll students? ";
  cin >> choice;
  cin.ignore();
  if(choice == 'i')
  {
      cout << "Enter id number: ";
      cin >> id;
      cin.ignore();
      index = find_student(students, length, id);
      if(index == -1)
      {
          cout << "Invalid id" << endl;
      }
      else
      {
        student_print(students[index]);
      }
  }
  else if(choice == 'a')
  {
      for(int i = 0; i < length; ++i)
      {
          student_print(students[i]);
      }
  }
  return;
}

// grade  a particular item {midterm, final, program} for all students
void grade(student students[], int length)
{
  int choice;
  cout << "What would you like to grade: " << endl;
  cout << "(0) Program" << endl;
  cout << "(1) Midterm" << endl;
  cout << "(2) Final" << endl;
  cin >> choice;
  cin.ignore();
  if(choice == 0)
  {
    for(int i = 0; i < length; ++i)
    {
      grade_program(students[i]);
    }
  }
  else if(choice == 1)
  {
    for(int i = 0; i < length; ++i)
    {
      grade_midterm(students[i]);
    }
  }
  else if(choice == 2)
  {
    for(int i = 0; i < length; ++i)
    {
      grade_final(students[i]);
    }
  }
  cout << endl;
  return;
}

// adjust a single score for a student for one item {midterm, final, program}
void adjust_grade(student students[], int length)
{
  int id;
  int choice;
  int index;

  cout << "Enter the id number of the student: ";
  cin >> id;
  index = find_student(students, length, id);
  if(index == -1)
  {
    cout << "No student found with id " << id << endl << endl;
    return;
  }
  cout << "What grade would you like to adjust: " << endl;
  cout << "(0) Program" << endl;
  cout << "(1) Midterm" << endl;
  cout << "(2) Final" << endl;
  cin >> choice;
  cin.ignore();

  if(choice == 0)
  {
      grade_program(students[index]);
  }
  else if(choice == 1)
  {
      grade_midterm(students[index]);
  }
  else if(choice == 2)
  {
      grade_final(students[index]);
  }
  
  cout << endl;
  return;
}

int main(void) {
    int num_students = 0;
    student students[SIZE];
    int menu_choice;
    char repeat = 'y';

    while(repeat != 'n')
    {
        menu_print();
        cin >> menu_choice;
        cin.ignore();
        // add a student
        if(menu_choice == 1)
        {
           add_student(students[num_students++]);
        }
        // grade an item
        else if(menu_choice == 2)
        {
            grade(students, num_students);
        }
        // class average
        else if(menu_choice == 3)
        {
            cout << "This totally isn't implemented yet!" << endl;
        }
        // adjust individual grade
        else if(menu_choice == 4)
        {
            adjust_grade(students, num_students);
        }
        // view student
        else if(menu_choice == 5)
        {
            view_students(students, num_students);
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

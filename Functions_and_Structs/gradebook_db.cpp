/**************************************
 * Manage grades for a class
 * Using file I/O to maintain persistance
 **************************************/

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

const int SIZE = 100;

struct student {
  int id; // id is assumed to be positive
  char name[SIZE];
  double midterm_grade;
  double final_grade;
  double program_grade;
};

// Function Prototypes
void menu_print(void);
void grade_program(student&);
void grade_midterm(student&);
void grade_final(student&);
int find_student(student*, int, int);
void student_print(student&);
void add_student(student&);
void view_students(student*, int);
void grade(student* , int);
void adjust_grade(student*, int);
int load(student*, char*);
void save(student*, int, char*);

int main(void) {
  int num_students = 0;
  student students[SIZE];
  int menu_choice;
  bool repeat = true;
  char filename[SIZE] = {};
  char choice;
  bool success = false;

  cout << "Would you like to load an existing gradebook(y/N): ";
  cin >> choice;
  cin.ignore();
  if(tolower(choice) == 'y')
  {
    while(!success){
      num_students = load(students, filename);
      if(num_students == -1)
      {
        cout << "Unable to load file. Try again? (Y/n): ";
        cin >> choice;
        cin.ignore();
        if(tolower(choice) == 'n')
        {
          num_students = 0;
          success = true;
        }
      }
      else
      {
        cout << "File loaded!" << endl;
        success = true;
      }
    }
  }


  while(repeat)
  {
      menu_print();
      cin >> menu_choice;
      cin.ignore();
      switch (menu_choice)
      {
        // add a student
        case 1: add_student(students[num_students++]);
                if(strcmp(filename, "") != 0) // autosave if filename defined
                  save(students, num_students, filename);
                break;
        // grade an item
        case 2: grade(students, num_students);
                if(strcmp(filename, "") != 0) // autosave if filename defined
                  save(students, num_students, filename);
                break;
        // class average
        case 3: cout << "This totally isn't implemented yet!" << endl;
                break;
        // adjust individual grade
        case 4: adjust_grade(students, num_students);
                if(strcmp(filename, "") != 0) // autosave if filename defined
                  save(students, num_students, filename);
                break;
        // view student
        case 5: view_students(students, num_students);
                break;
        // final grades
        case 6: cout << "This totally isn't implemented yet!" << endl;
                break;
        // quit
        case 7: repeat = false;
                break;
        default: cout << "Invalid selection." << endl;
                 break;
    }
  }
  cout << "Would you like to save your gradebook? (y/n): ";
  cin >> choice;
  if(tolower(choice) == 'y')
  {
    save(students, num_students, filename);
  }
  cout << "Thanks for using the gradebook!" << endl;
  return 0;
}

/*
* Loads student data from external file
* Returns the total number of students read in
* If the file fails to load returns -1 for error checking
*/
int load(student s[], char filename[])
{
  int i = 0; // tracks number of students read in
  ifstream fin; // Input file stream

  cout << "Enter the name of the gradebook file: ";
  cin.width(100);
  cin >> filename;
  fin.open(filename);

  if(!fin) // error in opening file
  {
    cout << "File not found!" << endl;
    return -1;
  }
  //read data from file into student data structure
  fin.get(s[i].name, 100, '\n'); // must try to read data to set up eof flag
  fin.ignore();
  while(!fin.eof()) // continues until end of file is reached
  {
    fin >> s[i].id;
    fin >> s[i].final_grade;
    fin >> s[i].midterm_grade;
    fin >> s[i].program_grade;
    fin.ignore();
    ++i;
    fin.get(s[i].name, 100, '\n');
    fin.ignore();
  }
  fin.close();

  return i;
}

/*
* Saves student data to external file
* If no current filename exists within the program
* Will prompt the user to provide one
*/
void save(student s[], int length, char filename[])
{
  ofstream fout;
  // set  up file to write out to
  // if no filename is provided get a new filename from the user
  if(strcmp(filename, "") == 0)
  {
    cout << "Enter a file to save your gradebook: ";
    cin >> filename;
    cin.ignore();
  }
  fout.open(filename);
  if(!fout)
  {
    cout << "Error opening file!" << endl;
    return;
  }

  // write students data structure to file
  // format : name \n
  //          id # \n
  //           final \t midterm \t program \n
  for(int i = 0; i < length; ++i)
  {
    fout << s[i].name << '\n';
    fout << s[i].id << '\n';
    fout << s[i].final_grade << '\t'
         << s[i].midterm_grade << '\t'
         << s[i].program_grade << '\n';
  }
  fout.close();
  return;

}

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
  char name[SIZE];
  int id = -1;
  int index;

  cout << "View (i)ndividual student or (a)ll students? ";
  cin >> choice;
  cin.ignore();
  if(choice == 'i')
  {
      cout << "Search by (i)d or (n)ame: ";
      cin >> choice;
      cin.ignore();
      if(tolower(choice) == 'i')
      {
        cout << "Enter id number: ";
        cin >> id;
        cin.ignore();
      }
      else if(tolower(choice) == 'n')
      {
        cout << "Enter student name: ";
        cin.get(name, 100, '\n');
        cin.ignore();
        for(int i = 0; i < length; ++i)
        {
          if(strcmp(name, students[i].name) == 0)
            id = students[i].id;
        }
      }
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
  cout << "(1) Program" << endl;
  cout << "(2) Midterm" << endl;
  cout << "(3) Final" << endl;
  cin >> choice;
  cin.ignore();
  if(choice == 1)
  {
    for(int i = 0; i < length; ++i)
    {
      if(students[i].program_grade == 0)
        grade_program(students[i]);
    }
  }
  else if(choice == 2)
  {
    for(int i = 0; i < length; ++i)
    {
      if(students[i].midterm_grade == 0)
        grade_midterm(students[i]);
    }
  }
  else if(choice == 3)
  {
    for(int i = 0; i < length; ++i)
    {
      if(students[i].final_grade == 0)
        grade_final(students[i]);
    }
  }
  else
  {
    cout << "Invalid Selection" << endl;
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
  cout << "(1) Program" << endl;
  cout << "(2) Midterm" << endl;
  cout << "(3) Final" << endl;
  cin >> choice;
  cin.ignore();

  if(choice == 1)
  {
      grade_program(students[index]);
  }
  else if(choice == 2)
  {
      grade_midterm(students[index]);
  }
  else if(choice == 3)
  {
      grade_final(students[index]);
  }

  cout << endl;
  return;
}

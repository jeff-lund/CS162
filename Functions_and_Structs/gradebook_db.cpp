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
int menu_print(void);
void grade_program(student&);
void grade_midterm(student&);
void grade_final(student&);
int find_student_id(student*, int, int);
int find_student_name(student*, int, char*);
void student_print(student&);
void add_student(student&);
void view_students(student*, int);
void grade(student* , int);
void adjust_grade(student*, int);
int load(student*, char*);
void save(student*, int, char*);
void class_average(student*, int);
void compute_grades(student*, int);
void wait(void);

int main(void) {

  student students[SIZE];
  char filename[SIZE] = {};
  char choice;
  int menu_choice;
  int num_students = 0;
  bool repeat = true;
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
      menu_choice = menu_print();
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
        case 3: class_average(students, num_students);
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
        case 6: compute_grades(students, num_students);
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

int menu_print(void)
{
  int n;

  cout << "1. Add a student" << endl;
  cout << "2. Grade an item" << endl;
  cout << "3. Get class averages" << endl;
  cout << "4. Adjust a students grade" << endl;
  cout << "5. View student information" << endl;
  cout << "6. Compute final grades" << endl;
  cout << "7. Quit" << endl;
  cout << "Enter an option: " << endl;
  cin >> n;
  cin.ignore();
  return n;
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

int find_student(student s[], int length)
{
    int index = -1;
    int id;
    char choice;
    char name[SIZE];

    cout << "Search by (i)d or (n)ame: ";
    cin >> choice;
    cin.ignore();

    if(tolower(choice) == 'i')
    {
      cout << "Enter id number: ";
      cin >> id;
      cin.ignore();
      index = find_student_id(s, length, id);
    }
    else if(tolower(choice) == 'n')
    {
      cout << "Enter student name: ";
      cin.get(name, 100, '\n');
      cin.ignore();
      index = find_student_name(s, length, name);
    }
    else
    {
      cout << "Invalid selection" << endl;
    }

    return index;
}

int find_student_id(student s[], int length, int id)
{
  int index = -1;
  for(int i = 0; i < length; ++i)
  {
    if(s[i].id == id)
    {
      index = i;
    }
  }
  return index;
}

int find_student_name(student s[], int length, char name[])
{
  int index = -1;
  for(int i = 0; i < length; ++i)
  {
    if(strcmp(name, s[i].name) == 0)
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
  int index;

  cout << "View (i)ndividual student or (a)ll students? ";
  cin >> choice;
  cin.ignore();
  if(choice == 'i')
  {
      index = find_student(students, length);
      if(index == -1)
      {
          cout << "Student not found." << endl;
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

  wait();
  return;
}

// grade  a particular item {midterm, final, program} for all students
// skips over a student if they already have a grade for the item
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
  int choice;
  int index;

  index = find_student(students, length);
  if(index == -1)
  {
    cout << "Student not found." << endl;
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

void class_average(student s[], int length)
{
  double final_avg = 0, program_avg = 0, midterm_avg = 0;
  for(int i = 0; i < length; ++i)
  {
    final_avg += s[i].final_grade;
    midterm_avg += s[i].midterm_grade;
    program_avg += s[i].program_grade;
  }
  final_avg /= length;
  midterm_avg /= length;
  program_avg /= length;

  cout << "Class averages for" << endl;
  cout << "\tPrograms: " << program_avg << endl;
  cout << "\tMidterm: " << midterm_avg << endl;
  cout << "\tFinal: " << final_avg << endl;
  wait();
  return;
}

void compute_grades(student s[], int length)
{
  // Assuming the final and midterm are 40% of your grade and the program is 20%
  double test_coef = 0.4, program_coef = 0.2, grade;

  cout << "Final grades: " << endl;
  for(int i = 0; i < length; ++i)
  {
    grade = s[i].final_grade * test_coef
          + s[i].midterm_grade * test_coef
          + s[i].program_grade * program_coef;
    cout << s[i].name << ": " << grade << endl;
  }

  wait();
  return;
}

void wait()
{
  cout << "Press anything to continue" << endl;
  cin.get();
}

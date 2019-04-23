/**************************************************
* CS162
* HR Management Software
**************************************************/

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int SIZE = 100; 

struct employee 
{
    int employee_id;
    char first_name[SIZE];
    char last_name[SIZE];
    bool hourly;
    double wage;
    double salary;    
    char job_title[SIZE];
};

void star_print(int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << '*';
    }
    cout << endl;
    
    return;
}

// prints out the related to an employee
void print_employee(employee& emp) 
{
    star_print(50);
    cout << "Employee information" << endl;
    star_print(50);
    
    cout << emp.first_name << " " << emp.last_name << endl;
    cout << "Job: " << emp.job_title << endl;

    if(emp.hourly)
    {
        cout << "Hourly Wage: $" << emp.wage << "/hour" << endl;
    }
    else if(!emp.hourly)
    {
        cout << "Salary: $" << emp.salary << " per year" << endl;
    }
    
    return;
}

// fill out the information associated with an employee
void add_employee(employee& emp)
{
    char input;
    
    cout << "Enter the employees first name: ";
    cin >> emp.first_name;
    
    cout << "Enter the employees last name: ";
    cin >> emp.last_name;
    cin.ignore();    
    cout << "Enter the employees job title: ";
    cin.get(emp.job_title, SIZE, '\n');
    
    cout << "Is the employee (h)ourly or (s)alaried? ";
    cin >> input;
    if(tolower(input) == 'h')
    {
        emp.hourly = true;
        cout << "Enter the employees hourly wage: ";
        cin >> emp.wage;
    }
    else if(tolower(input) == 's')
    {
        emp.hourly = false;
        cout << "Enter the employees annual salary: ";
        cin >> emp.salary;
    }
    
    cout << "Added " << emp.first_name << " " 
        << emp.last_name << " to the roster." << endl;

    return;
}   

int main(void)
{
    employee dave;
    
    add_employee(dave);
    print_employee(dave);
    
     
    int index = 0;
    employee my_employees[SIZE];
    star_print(50);
    add_employee(my_employees[index++]);
    star_print(50);
    star_print(50);
    my_employees[1] = dave;
    strcpy(my_employees[1].first_name, "Drew");
    cout << dave.first_name << endl;
    cout << my_employees[1].first_name << endl;
    
    ++index;
    for(int i = 0; i < index; ++i)
        print_employee(my_employees[i]);
    
    return 0;
}

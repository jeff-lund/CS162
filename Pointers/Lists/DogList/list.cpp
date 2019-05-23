#include <iostream>
#include <cstring>
#include "node.h"
using namespace std;

node::~node()
{
    delete [] a_dog.name;
    delete [] a_dog.breed;
    delete [] a_dog.trick;
}

list::list()
{
  head = NULL;
  return;
}

list::~list()
{
  node *temp;
  while(head != NULL)
  {
    temp = head->next;
    //delete [] head->a_dog.name;
    //delete [] head->a_dog.breed;
    //delete [] head->a_dog.trick;
    delete head;
    head = temp;
  }

  return;
}

void display_dog(dog & d)
{
  cout << d.name << " is a "
       << d.breed << " that can perform "
       << d.trick << "." << endl;
  return;
}

void list::display_all(void)
{
  node *current = head;
  if(head == NULL)
  {
    cout << "List is empty." << endl;
    return;
  }
  while(current)
  {
    display_dog(current->a_dog);
    current = current->next;
  }
  cout << endl;
  return;
}

// insert node into the list in ascending order
void list::add(dog d)
{
  node *current, *previous, *temp;
  // always check if list is empty
  if(head == NULL)
  {
    head = new node;
    head->a_dog = d;
    head->next = NULL;
  }
  else
  {
    temp = new node;
    temp->a_dog = d;
    // replacing the head
    if(strcmp(head->a_dog.name, temp->a_dog.name) > 0)
    {
        temp->next = head;
        head = temp;
    }
    // replacing somehwere in the middle or end
    else
    {
      current = head;
      // not at the end of the list AND haven't reached the place to insert
      while(current != NULL && strcmp(current->a_dog.name, temp->a_dog.name) < 0)
      {
        previous = current;
        current = current->next;
      }

      temp->next = current;
      previous->next = temp;
    }
  }
  return;
}

int list::count(void)
{
  node *current = head;
  int count = 0;
  while(current != NULL)
  {
    ++count;
    current = current->next;
  }
  return count;
}

void list::remove(const char* search)
{
  node *current, *previous;
  if(head == NULL)
  {
    return;
  }
  // removing head of list
  if(strcmp(head->a_dog.name, search) == 0)
  {
    current = head;
    head = head->next;
    // why not just delete head?
    //delete [] current->a_dog.name;
    //delete [] current->a_dog.breed;
    //delete [] current->a_dog.trick; 
    delete current; // Make sure to deallocate your nodes
  }
  // removing from middle or end of list
  else
  {
    current = head;
    while(current != NULL &&  strcmp(current->a_dog.name, search) != 0)
    {
      previous = current;
      current = current->next;
    }
    // Node not found
    if(current != NULL)
    {
      previous->next = current->next;
      //delete [] current->a_dog.name;
      //delete [] current->a_dog.breed;
      //delete [] current->a_dog.trick;
      delete current;
    }
    else
    {
      cout << "Dog not found in list." << endl;
    }
  }
  return;
}

dog build_dog(const char* name, const char* breed, const char* trick)
{
  dog new_dog;
  new_dog.name = new char[strlen(name) + 1];
  new_dog.breed = new char[strlen(breed) + 1];
  new_dog.trick = new char[strlen(trick) + 1];
  strcpy(new_dog.name, name);
  strcpy(new_dog.breed, breed);
  strcpy(new_dog.trick, trick);
  
  return new_dog;
}

dog interactive_build_dog()
{
    char buffer[500];
    dog a_dog;

    cout << "What is the dog's name? ";
    cin.get(buffer, 500, '\n');
    cin.ignore();
    a_dog.name = new char[strlen(buffer) + 1];
    strcpy(a_dog.name, buffer);

	cout << "What breed is the " << a_dog.name << "? ";
    cin.get(buffer, 500, '\n');
    cin.ignore();
    a_dog.breed = new char[strlen(buffer) + 1];
    strcpy(a_dog.breed, buffer);

	cout << "What trick can " << a_dog.name << " perform? ";
    cin.get(buffer, 500, '\n');
    cin.ignore();
    a_dog.trick = new char[strlen(buffer) + 1];
    strcpy(a_dog.trick, buffer);
    
    cout << endl;
	return a_dog;
}

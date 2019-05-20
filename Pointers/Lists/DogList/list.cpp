#include <iostream>
#include <cstring>
#include "node.h"
using namespace std;

list::list()
{
  head = NULL;
  return;
}

list::~list()
{
  node *temp = head;
  if(head == NULL)
  {
    return;
  }

  while(head->next != NULL)
  {
    head = head->next;
    delete [] temp->a_dog.name;
    delete [] temp->a_dog.breed;
    delete [] temp->a_dog.trick;
    delete temp;
    temp = head;
  }
  delete [] temp->a_dog.name;
  delete [] temp->a_dog.breed;
  delete [] temp->a_dog.trick;
  delete temp;

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

#include <iostream>
#include "node.h"
using namespace std;

list::list()
{
  head = NULL;
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
    cout << current->val << " ";
    current = current->next;
  }
  cout << endl;
  return;
}

// Add a node at the beginning of a linked list
void list::add_b(int value)
{
  node *temp;
  if(head == NULL)
  {
    head = new node;
    head->val = value;
    head->next = NULL;
  }
  else
  {
    temp = new node;
    temp->val = value;
    temp->next = head;
    head = temp;
  }
  return;
}

// add a node to the end of the list
void list::add_e(int value)
{
  node *current, *temp;
  // always check if list is empty
  if(head == NULL)
  {
    head = new node;
    head->val = value;
    head->next = NULL;
  }
  else
  {
    current = head;
    // find the end of the list
    // why not while(current != NULL)
    while(current->next != NULL)
    {
      current = current->next;
    }
    // found the end, ready to add
    temp = new node;
    temp->val = value;
    temp->next = NULL;
    current->next = temp;
  }
  return;
}

// insert node into the list in ascending order
void list::add_sort(int value)
{
  node *current, *previous, *temp;
  // always check if list is empty
  if(head == NULL)
  {
    head = new node;
    head->val = value;
    head->next = NULL;
  }
  else
  {
    temp = new node;
    temp->val = value;
    // replacing the head
    if(head->val > value)
    {
        temp->next = head;
        head = temp;
    }
    // replacing somehwere in the middle or end
    else
    {
      current = head;
      // not at the end of the list AND haven't reached the place to insert
      /*
      while(current != NULL && current->val < value)
      {
        previous = current;
        current = current->next;
      }
      temp->next = current;
      previous->next = temp;
        */
      while(current->next != NULL && current->next->val < value)
          current = current->next;
      temp->next = current->next;
      current->next = temp;
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

void list::remove(int value)
{
  node *current, *previous;
  if(head == NULL)
  {
    return;
  }
  // removing head of list
  if(head->val == value)
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
    while(current != NULL && current->val != value)
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
      cout << "Value not found in list." << endl;
    }
  }
  return;
}

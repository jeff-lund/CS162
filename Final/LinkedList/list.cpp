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

// New Functions
// Display the last node in a Linked list
void list::display_last()
{
    node *current;
    current = head;
    // Check if list is empty
    if(current == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    // Traverse list to find last node
    while(current->next != NULL)
        current = current->next;
    // reached the last node
    // print out the value
    cout << current->val << endl;

    return;
}

// remove the middle node from a list
// returns the value of the node removed
int list::remove_middle()
{
    node *current, *previous;
    int total_nodes;
    int val;
    // check for empty list
    if(head == NULL)
        return -1;
    // list not empty
    else
    {
        current = head;
        // get count of nodes in list
        total_nodes = 0;
        while(current != NULL)
        {
            ++total_nodes;
            current = current->next; 
        }
        // reset current to the head of the list
        total_nodes /= 2;
        current = head;
        previous = current;
        // traverse to middle node
        for(int i = 0; i < total_nodes; ++i)
        {
            previous = current;
            current = current->next;
        }
        // move previous to point around the node we are deleting
        previous->next = current->next;
        val = current->val;
        // delete the node
        delete current;
        return val;


    }
}

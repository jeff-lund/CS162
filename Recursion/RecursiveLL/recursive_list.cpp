#include <iostream>
#include "node.h"
using namespace std;

list::list()
{
  head = NULL;
}

void list::display()
{
  display_r(head);
  cout << endl;
}

void list::add(int n)
{
  add_r(head, n);
}

void list::remove(int n)
{
  remove_r(&head, n);
}

void list::count()
{
  count_r(head);
}
/******* Your implementations ************************/
void list::count_r(node * head)
{
  // insert your code here
}

/************* END new implementations *******************/

void list::display_r(node * head)
{
  if(head != NULL)
  {
    // What happens if we switch these two calls?
    cout << head->val << " ";
    display_r(head->next);
  }
  return;
}

void list::add_r(node * & head, int n)
{
    if(head == NULL)
    {
      head = new node;
      head->val = n;
      head->next = NULL;
    }
    else
      add_r(head->next, n);
}

void list::remove_r(node * * head, int n)
{
  node * temp;
  // empty list or no match
  if(*head == NULL)
  {
    cout << "No match found." << endl;
    return;
  }
  // found a match
  if((*head)->val == n)
  {
    temp = *head;
    *head = (*head)->next;
    delete temp;
  }
  else // recursive call
    remove_r(&(*head)->next, n);
}

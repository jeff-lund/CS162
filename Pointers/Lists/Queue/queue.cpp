#include <iostream>
#include "queue.h"
using namespace std;

queue::queue()
{
  head = tail = NULL;
}

void queue::push(char * c)
{
  node *temp;
  temp = new node();
  temp->word = c;
  temp->next = NULL;
  if(head == NULL)
  {
    head = temp;
    tail = temp;
    temp->next = NULL;
  }
  else
  {
    tail->next = temp;
    tail = temp;
  }
  return;
}

char* queue::pop()
{
  node *temp;
  char* ret;

  if(is_empty())
  {
    cout << "Queue is empty!" << endl;
    return "";
  }
  // one element in list
  else if(tail == head)
  {
    ret = head->word;
    delete head;
    // delete tail; // Do we need to do this? What happens?
    head = tail = NULL;
    return ret;
  }
  else // more than 1 element in the list
  {
    ret = head->word;
    temp = head;
    head = head->next;
    delete temp;
    return ret;
  }
}

bool queue::is_empty()
{
  return head == NULL;
}

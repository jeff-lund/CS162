#include <iostream>
#include "pythonic_list.h"
using namespace std;

list::list()
{
  arr = new int[10];
  last_index = 0;
  max_size = 10;

  return;
}

void list::append(int val)
{
  arr[last_index++] = val;
  if(last_index == max_size)
    reallocate();
  return;
}

int list::pop()
{
  int temp = arr[--last_index];
  return temp;
}

void list::print()
{
  cout << "[" ;
  for(int i = 0; i < last_index - 1; ++i)
    cout << arr[i] << ", ";
  cout << arr[last_index-1] << "]" << endl;
}

void list::reallocate()
{
  int *temp;
  max_size *= 2;
  temp = new int[max_size];
  for(int i = 0; i < last_index; ++i)
    temp[i] = arr[i];
  delete [] arr;
  arr = temp;

  return;
}

int list::get(int i)
{
  if(i < last_index)
    return arr[i];
  else
    cout << "List index out of range" << endl;
  return 0;
}

bool list::store(int index, int value)
{
  if(index >= last_index)
  {
    cout << "List index out of range" << endl;
    return false;
  }
  arr[index] = value;
  return true;
}

#include <iostream>
using namespace std;

class list {
    public:
      list();
      void append(int);
      int pop();
      void print();
    private:
      int *arr;
      int last_index;
      int max_size;
      void reallocate();
};

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

int main(void)
{
  list l;
  int x;
  l.append(5);
  l.append(6);
  l.append(10);
  l.print();
  x = l.pop();
  cout << "Value popped: " << x << endl;
  l.print();
  for(int i = 10; i < 25; ++i)
    l.append(i);
  l.print();

  return 0;
}

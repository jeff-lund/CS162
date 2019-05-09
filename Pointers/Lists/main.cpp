#include <iostream>
#include "pythonic_list.h"
using namespace std;

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
  cout << l.get(4) << endl;
  l.store(4, 100);
  l.print();

  return 0;
}

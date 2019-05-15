#include <iostream>
#include "queue.h"
using namespace std;

int main(void)
{
  queue q;
  char* arr[] = {"apple", "pear", "pineapple", "starfruit", "durian"};

  for(int i = 0; i < 5; ++i)
  {
    cout << "Adding " << arr[i] << endl;
    q.push(arr[i]);
  }
  cout << endl << "Popping items" << endl;
  while(!q.is_empty())
  {
    cout << q.pop() << endl;
  }

  return 0;
}

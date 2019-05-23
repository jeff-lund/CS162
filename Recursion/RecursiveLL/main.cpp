#include <iostream>
#include "node.h"
using namespace std;

int main(void)
{
  list my_list;
  my_list.add(12);
  my_list.display();
  my_list.add(25);
  my_list.display();
  my_list.add(37);
  my_list.display();
  my_list.add(49);
  my_list.display();
  my_list.add(51);
  my_list.display();
  my_list.remove(49);
  my_list.display();
  my_list.remove(12);
  my_list.display();
  my_list.remove(51);
  my_list.display();
  my_list.remove(0);
  my_list.display();

  return 0;
}

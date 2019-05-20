#include <iostream>
#include <cstring>
#include "node.h"
using namespace std;

int main(void)
{
  dog this_dog;
  list my_list;

  this_dog = build_dog("Spark", "Golden Retriever", "Fetch");
  my_list.add(this_dog);
  my_list.display_all();

  this_dog = build_dog("Bork", "Poodle", "Yapping");
  my_list.add(this_dog);
  my_list.display_all();

  this_dog = build_dog("Fido", "Beagle", "Play Dead");
  my_list.add(this_dog);
  my_list.display_all();

  this_dog = build_dog("Abelsworth", "Black Lab", "Shake");
  my_list.add(this_dog);
  my_list.display_all();

  this_dog = build_dog("Kilo", "Pit Bull", "Bite");
  my_list.add(this_dog);
  my_list.display_all();

  my_list.remove("Fido");
  my_list.display_all();

  my_list.remove("Abelsworth");
  my_list.display_all();

  my_list.remove("Spot");
  my_list.display_all();

  my_list.~list(); // call destructor

  list a_list; // what happens if we use the destructor on an empty list
  a_list.~list();

  return 0;
}

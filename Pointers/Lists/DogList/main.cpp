#include <iostream>
#include <cstring>
#include "node.h"
using namespace std;

const bool MANUAL = false;

int main(void)
{
  list my_list;
  if(!MANUAL)
  {

    my_list.add(build_dog("Spark", "Golden Retriever", "Fetch"));
    my_list.display_all();

    my_list.add(build_dog("Bork", "Poodle", "Yapping"));
    my_list.display_all();

    my_list.add(build_dog("Fido", "Beagle", "Play Dead"));
    my_list.display_all();

    my_list.add(build_dog("Abelsworth", "Black Lab", "Shake"));
    my_list.display_all();

    my_list.add(build_dog("Kilo", "Pit Bull", "Cuddle"));
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
  }
  else
  {
    for(int i = 0; i < 5; ++i)
    {
        my_list.add(interactive_build_dog());
        my_list.display_all();
    }
  }

  return 0;
}

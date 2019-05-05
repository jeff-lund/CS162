#include <iostream>
using namespace std;
#include "clock.h"

int main(void)
{
    int x, y, z;

    Clock my_clock;
    my_clock.setTime(10, 15, 20);
    my_clock.printTime();

    my_clock.incrementSeconds();
    my_clock.printTime();

    my_clock.getTime(x, y, z);
    cout << x << " " << y << " " << z << endl;

    Clock other_clock;
    other_clock.setTime(22, 58, 59);
    other_clock.printTime();
    other_clock.incrementSeconds();
    other_clock.printTime();
    other_clock.incrementMinutes();
    other_clock.printTime();
    other_clock.incrementHours();
    other_clock.printTime();

    return 0;
}

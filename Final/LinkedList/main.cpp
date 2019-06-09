#include "node.h"
#include <iostream>
using namespace std;

int main(void)
{
    list my_list;
    int arr[] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; ++i)
    {
        cout << "Adding " << arr[i] << " to the list." << endl;
        // Adding at the end
        my_list.add_e(arr[i]);
        my_list.display_all();
    }
    cout << "List contents: ";
    my_list.display_all();
    cout << "Number of items in list: " << my_list.count() << endl;
    // new functions
    cout << "Last Node: ";
    my_list.display_last();
    cout << "value removed: " << my_list.remove_middle() << endl;
    my_list.display_all();

    return 0;
}

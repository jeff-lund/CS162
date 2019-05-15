#include "node.h"
#include <iostream>
using namespace std;

int main(void)
{
    list my_list;
    int arr[] = {65, 42, 51, 99, 1};
    for(int i = 0; i < 5; ++i)
    {
        cout << "Adding " << arr[i] << " to the list." << endl;
        my_list.add_b(arr[i]);
        //my_list.add_e(arr[i]);
        //my_list.add_sort(arr[i]);
        my_list.display_all();
    }
    cout << "List contents: ";
    my_list.display_all();
    cout << "Number of items in list: " << my_list.count() << endl;
    /*
    cout << "Deleting Nodes" << endl;
    cout << "Removing 1 from the list" << endl;
    my_list.remove(1);
    my_list.display_all();
    cout << "Removing 51 from the list" << endl;
    my_list.remove(51);
    my_list.display_all();
    cout << "Removing 99 from the list" << endl;
    my_list.remove(99);
    my_list.display_all();
    cout << "Number of items in list: " << my_list.count() << endl;
    my_list.remove(101);
    */
    return 0;
}

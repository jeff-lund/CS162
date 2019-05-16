#include "linked_list.h"
#include <iostream>
using namespace std;
int main(void)
{   
    node *head = new node;
    node *current;
    head->value = -1;
    head->next = NULL;
    default_list(head);
    current = head;
    
    while(current->next != NULL)
    {
        current = current->next;
        cout << current->value << endl;
    }
    return 0;
}

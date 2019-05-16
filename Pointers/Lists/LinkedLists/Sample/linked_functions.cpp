#include <iostream>
#include "linked_list.h"
using namespace std;

void add(node *n, int val)
{
    
    node *temp = new node;
    temp->value = val;
    temp->next = NULL;
    n->next = temp;

    return;
}

void default_list(node *head)
{    
    node *current = head;
    int arr[] = {12, 21, 43, 97, 112, 240};
    for(int i = 0; i < 5; ++i)
    {
        add(current, arr[i]);
        current = current->next;
    }
    return;
}

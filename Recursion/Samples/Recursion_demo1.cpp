
//Add an item at the end of a linear linked list

//iteratively (with a loop)
//Case 1 - empty list, insert at the beginning
//Case 2 - otherwise, traverse to the end

void add_at_end(node * & head) //pass in my LLL
{
//Why pass by reference?
//Because - head COULD be modified! If the list is 
//empty, then I need to be able to say:
//head = new node;

//Case 1 - empty list
  if (NULL == head) // if (!head)
  {
    head = new node;
    //store the data - maybe read it in
    head->next = NULL;
  } else
  {
    node * current = head;
    while (current->next != NULL) //stop at last
    {
        current = current->next;
    }
    //where is current???????? pointing to
    //the last node....
    //connect up
    current->next =new node;
    current = current->next;
    current->next = NULL;
    //Save the data for this node that
    //current is psoint to!
  }

}

//RECURSIVE SOLUTION!!!!!!!!!!!!!!!!

void add_at_end(node * & head) //pass in my LLL
{
//Why pass by reference?
//Because - head WILL be modified at some point

  if (NULL == head) // if (!head)
  {
    head = new node;
    //store the data - maybe read it in
    head->next = NULL;
  } else
    add_at_end(head->next);
}






    
    
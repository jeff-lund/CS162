//Write the code to remove the last node
//from a LLL -- first iteratively

void remove_last(node * & head)
{
   if(head == NULL) //nothing to remove!!!
      return;
   if (head->next == NULL) //only one item?
   {
       delete [] head->name;
       delete head;
       head = NULL;
   }
   else //more than one node
   {
      node * current = head->next;
     node * previous = head;
     while (current->next)
     {
       previous  = current;
       current = current->next;
     }
     delete [] current->name;
     delete current; //delete the last node
     previous->next = NULL; //reset the new last
                            //node's next pointer
   }
}

//Write the code to remove the last node
//from a LLL -- now recursively

void remove_last(node * & head)
{
   if(head == NULL) //nothing to remove!!!
      return;
   if (head->next == NULL) //only one item?
   {
       delete [] head->name;
       delete head;
       head = NULL;
   }
   else //more than one node
   {
      remove_last(head->next);
   }
}

//Add all values in an array of
//integers
//Stopping condition: When index is the same
//as the number of items
//Assumption: First time through the index must
//be zero
//Result: The sum total is going to be returned

int sum(int index, int array[], int num_items)
{
   if(index >= num_items) //Stopping
      return 0;
   return array[index]+sum(index+1,array,num_items);
}

//Or, count down, from num_items to zero
int sum(int array[], int num_items)
{
   if(num_items < 1) //NOTHING TO DO!
       return 0;
   return array[num_items-1]+
           sum(array, num_items-1);
}
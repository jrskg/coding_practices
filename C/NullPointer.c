#include <stdio.h>
 
int main()
{
   int a = 34;
   int* ptr = NULL;
   //ptr = &a;
   if(ptr != NULL)
   {
      printf("The value of a is %d\n",ptr);
   }
   else
   {
      printf("Ptr is a NULL pointer and it cannot be dereferenced\n");
   }
	return 0;
}
 
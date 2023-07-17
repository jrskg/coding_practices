#include <stdio.h>
 
int main()
{
  int a = 45;
  float b = 2.456;
  void* ptr;
  ptr = &a;
  printf("The value of a is %d\n",*((int*)ptr));
  ptr = &b;
  printf("The value of b is %.3f\n",*((float*)ptr));
	return 0;
}
 

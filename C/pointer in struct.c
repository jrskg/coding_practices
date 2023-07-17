#include <stdio.h>

struct suraj{
  int roll;
  char name[15];
  float salary;
};
 
int main()
{
 struct suraj s;
 struct suraj *ptr;
 ptr = &s;
// (*ptr).roll = 2;
// printf("%d",(*ptr).roll);
  ptr->roll = 2;
  printf("%d",ptr->roll);
 
	return 0;
}
 
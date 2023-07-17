#include <stdio.h>

struct suraj{
  int roll;
  char name[15];
  float salary;
};
 
int main()
{
 struct suraj s[10];
 s[0].roll = 1;
 s[0].salary = 1000.5;
 strcpy(s[0].name,"Arun");

 printf("%d\n",s[0].roll);
 printf("%.1f\n",s[0].salary);
 printf("%s\n",s[0].name);
	return 0;
}
 
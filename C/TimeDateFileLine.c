#include <stdio.h>
 
int main()
{
	printf("The time is %s\n",__TIME__);
 printf("The date is %s\n",__DATE__);
 printf("The file is %s\n",__FILE__);
 printf("The line is %d\n",__LINE__);
 printf("ANSI:%d\n",__STDC__);
	return 0;
}
 
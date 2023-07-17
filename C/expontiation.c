#include <stdio.h>
 
int main()
{
	 int m, n;
  long long int val = 1;
  printf("Enter The number and the power\n");
  scanf("%d %d", &m, &n);
  for(int i = 0; i < n; i++)
  {
    val = val * m;
  }
  printf("The value is %lld", val);
	return 0;
}
 
#include <stdio.h>

int main()
{
  int arr[] = {2,4,5,8,8,1,2,5,6};
  int a = 0;
  
 // a = arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5] + arr[6];
 // printf("%d",a);

  for(int i = 0; i < 9; i++)
   {
     a = a + arr[i];
   }
  printf("The sum is %d",a);

	return 0;
}
 
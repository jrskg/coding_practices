#include <stdio.h>

int factorial(int number)
{
    int a = 1;
    for(int i = 1; i <= number; i++)
      {
         a = a * i;
      }
    return a;
}

int main()
{
    int num;
    printf("Enter the number you want the factorial of\n");
    scanf("%d",&num);
    printf("The factorial of %d is %d\n",num,factorial(num));



    return 0;
   
}

#include <stdio.h>

int main()
{
    int n;
    int m = 1;
    printf("Enter a number:\n");
    scanf("%d",&n);
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            m = 0;
        }
    }

    if(n<2)
    {
      printf("%d is not a prime number.\n",n);
    }
    else if(m)
    {
      printf("%d is a prime number.\n",n);
    }
    else
    {
      printf("%d is a not prime number.\n",n);
    }
    return 0;
}

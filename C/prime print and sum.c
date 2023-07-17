#include <stdio.h>

int isPrime(int n)
{
    if(n==0 || n==1)
    {
        return 0;
    }
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int min, max, sum = 0;
    printf("Enter the two numbers:\n");
    scanf("%d %d",&min, &max);
    if(min > max)
    {
        min = min + max;
        max = min - max;
        min = min - max;
    }

    printf("The prime numbers are:\n");
    for(int i = min; i <= max; i++)
    {
        if(isPrime(i))
        {
            printf("%d ",i);
            sum = sum + i;
        }
    }
    printf("\nThe sum of all prime numbers is %d\n",sum);
    return 0;
}

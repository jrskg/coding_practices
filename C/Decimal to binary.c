#include <stdio.h>

int main()
{
    int n;
    int rem;
    int a[50];
    int i = 0;
    printf("Enter the decimal number:\n");
    scanf("%d",&n);



    if(n == 0)
    {
        printf("The binary number is 00\n");
    }
    else if(n == 1)
    {
        printf("The binary number is 01\n");
    }
    else
    {
        while(n)
        {
            rem = n % 2;
            n = n / 2;
            a[i] = rem;
            i++;
        }

        printf("The binary number is ");

        for(int j = i - 1; j >= 0; j--)
        {
            printf("%d",a[j]);
        }
    }
    return 0;
}

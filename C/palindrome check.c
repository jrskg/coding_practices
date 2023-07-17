#include <stdio.h>

int suraj(n)
{
    int rev = 0;
    int old_n = n;
    while(n != 0)
    {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }

    if(old_n == rev)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int num;
    printf("Enter a number to check:");
    scanf("%d",&num);

    if(suraj(num))
    {
        printf("This is a palindrome number.\b");
    }
    else
    {
        printf("This is not a palindrome number.\n");
    }
    return 0;
}

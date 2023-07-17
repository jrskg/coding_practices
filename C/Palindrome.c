#include <stdio.h>

int suraj(n)
{
    int rev = 0;
    while(n != 0)
    {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }
    return rev;
}

int main()
{
    int num;
    printf("Enter a number to check:\n");
    scanf("%d",&num);
    int rev = suraj(num);
    printf("The reversed number is %d\n",rev);
    if(num == rev)
    {
        printf("This is a palindrome number.\b");
    }
    else
    {
        printf("This is not a palindrome number.\n");
    }
    return 0;
}
    
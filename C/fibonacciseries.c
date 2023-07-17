#include <stdio.h>

int fib_recursive(int n)
{
    if(n==1||n==2) {
        return n-1;
    }
    else {
        return fib_recursive(n-1)+fib_recursive(n-2);
    }

}

fib_iterative(int n)
{
    int a=0;
    int b=1;

    for(int i = 0; i < n-1; i++ )
    {
        b = a+b;
        a = b-a;

    }
    return a;
}

int main()
{   char input;
    int number;
    while(1)
    {   printf("Press R to use recursive approach\nPress I to use iterative approach\nPress B to use both approach\nPress Q to quit\n");
        scanf(" %c",&input);
        switch(input)
        {
        case'Q':
            printf("Quitting the program . . .\n");
            goto end;
            break;

        case'R':
            printf("Enter the index to get fibonacci series\n");
            scanf("%d",&number);
            printf("The value of fibonacci number at position no %d using recursive approach is %d\n\n\n",number,fib_recursive(number));
            break;

        case'I':
            printf("Enter the index to get fibonacci series\n");
            scanf("%d",&number);
            printf("The value of fibonacci number at position no %d using iterative approach is %d\n\n\n",number,fib_iterative(number));
            break;

        case'B':
                printf("Enter the index to get fibonacci series\n");
            scanf("%d",&number);
            printf("The value of fibonacci number at position no %d using iterative approach is %d\n\n",number,fib_iterative(number));
            printf("The value of fibonacci number at position no %d using recursive approach is %d\n\n\n",number,fib_recursive(number));
            break;
        default:
            printf("You have entered a invalid input");
            goto end;
            break;
        }
    }
end:
    return 0;
}

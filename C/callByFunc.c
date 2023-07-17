#include <stdio.h>

int sum(int a, int b)
{
    return a+b;
}

void greetGm(int (*fptr)(int, int))
{
    printf("Good morning user\n");
    printf("The sum is %d\n\n",fptr(5,5));
}

void greetGe(int (*sptr)(int, int))
{
    printf("Good evening user\n");
    printf("The sum is %d\n\n",sptr(8,8));
}

int main()
{   char input;
    int (*ptr)(int, int);
    ptr =&sum;
    while(1)
    {
        printf("Press M for morning, E for evening and Q for quit\n");
        scanf(" %c",&input);
        switch(input)
        {
        case'M':
            greetGm(ptr);
            break;

        case'E':
                greetGe(ptr);
            break;

        case'Q':
            printf("Quitting the program. . .\n");
            goto end;
            break;

        default:
            printf("Invalid input\n");
            goto end;
        }
    }
end:
    return 0;
}

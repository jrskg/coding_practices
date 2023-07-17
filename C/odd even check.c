#include <stdio.h>

void oddEven(int a)
{
    if(a % 2 == 1)
    {
        printf("It's a odd number\n\n");
    }
    else
    {
        printf("It's a even number\n\n");
    }
}

int main()
{
    int a;
    char input;
    while(1)
    {
        printf("Press c to continue and q to quit\n");
        scanf(" %c",&input);
        switch(input)
        {
        case'c':
            printf("Enter a num to check:");
            scanf("%d",&a);
            oddEven(a);
            break;

        case'q':
            printf("Quitting the program. . .\n");
            goto end;
            break;

        default:
            printf("Invalid input!\n");
            break;
        }
    }

end:
    return 0;
}

#include<stdio.h>

int main()
{
    int a;
    char input;
    printf("Welcome here you can see multiplication table\n");

    while(1)
    {
        printf("press q to quit and c to continue\n");
        scanf(" %c",&input);

        switch(input)
        {

        case'q':
            printf("Quitting the program . . .\n");
            goto end;
            break;

        case'c':
                printf("Enter a number\n");
            scanf("%d",&a);

            if(a>100)
            {
                printf("You only can see table upto 100\n\n");
                break;
            }

            else
            {
                printf("The table is as follows\n");
                for(int i=1; i<11; i++)
                {

                    printf("%d * %d = %d\n",a,i,a*i);

                }


            }

            break;
        default:
            printf("You have entered a invalid input\n");
            goto end;
            break;
        }

    }
end:

    return 0;
}

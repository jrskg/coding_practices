#include <stdio.h>

void Starpattern(int rows)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

}


void reverseStarpattern(int rows)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j <= rows - i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

}



int main()
{
    int rows;
    char input;
    while(1)
    {

        printf("Press A for star pattern.\nPress B for reverse star pattern.\nPress Q to quit\n");
        scanf(" %c",&input);


        switch(input)
        {
        case'Q':
            printf("Quitting the program . . .\n");
            goto end;
            break;

        case'A':
                printf("How many rows do you want to print ?\n");
            scanf("%d",&rows);
            Starpattern(rows);
            break;

        case'B':
                printf("How many rows do you want to print ?\n");
            scanf("%d",&rows);
            reverseStarpattern(rows);
            break;

        default:
            printf("Invalid input\n");
            goto end;
            break;

        }

    }
end:
    return 0;
}

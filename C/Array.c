#include <stdio.h>

int main()
{
    int marks[][4]= { {2,4,5,6}, {5,2,4,6} };

    for(int i = 0; i<2; i++)
    {
        for(int j=0; j<4; j++)
        {
            //printf("The value of %d and %d element of the array is %d\n",i,j,marks[i][j]);
            printf("%d",marks[i][j]);
        }
        printf("\n");
    }


    /*
        for(int i = 0; i<4; i++)
        {
            printf("Enter the value of %d element of the array\n",i);
            scanf("%d",&marks[i]);

        }
        for(int i = 0; i<4; i++)
        {

            printf("The value of %d element of the array is %d\n",i,marks[i]);

        }


    /*
        /* int marks[4]= {5,6,7,8};

             printf("The mark of student 1 is %d\n",marks[0]);
             printf("The mark of student 2 is %d\n",marks[1]);
             printf("The mark of student 3 is %d\n",marks[2]);
             printf("The mark of student 4 is %d\n",marks[3]);
         */
    return 0;
}

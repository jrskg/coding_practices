#include <stdio.h>
#include <stdlib.h>

int main()
{   /*   //*****use of malloc****
       int* ptr;
       int n;

       printf("Enter the number of size of array you want to create:\n");
       scanf("%d",&n);

       ptr = (int*)malloc(n*sizeof(int));
       for(int i = 0; i < n; i++)
       {
           printf("Enter the value at no %d of the array:\n",i);
           scanf("%d",&ptr[i]);
       }

       for(int i = 0; i < n; i++)
       {
           printf("The value at no %d is %d\n",i,ptr[i]);
       }
    */

    //******use of calloc*****

    int* ptr;
    int n;

    printf("Enter the number of size of array you want to create:\n");
    scanf("%d",&n);

    ptr = (int*)calloc(n,sizeof(int));
    for(int i = 0; i < n; i++)
    {
        printf("Enter the value at no %d of the array:\n",i);
        scanf("%d",&ptr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        printf("The value at no %d is %d\n",i,ptr[i]);
    }



// ***** use of realloc****


    printf("Enter the new number of size of array you want to create:\n");
    scanf("%d",&n);

    ptr = (int*)realloc(ptr,n*sizeof(int));
    for(int i = 0; i < n; i++)
    {
        printf("Enter the new value at no %d of the array:\n",i);
        scanf("%d",&ptr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        printf("The new value at no %d is %d\n",i,ptr[i]);
    }

    free(ptr);

    return 0;
}

#include <stdio.h>

int func1(int array[])
{
    for(int i = 0; i < 5; i++)
    {
        printf("The value at %d is %d\n",i,array[i]);

    }

    //array[0] = 34;// very important point that if you change any value here, it gets reflected in main()

    return 0;
}



void func2(int* ptr)
{
    for(int i = 0; i < 5; i++)
    {
        // printf("The value at %d is %d\n",i,ptr[i]);
        printf("The value at %d is %d\n",i,*(ptr+i));
    }
    *(ptr + 2) = 12;
}


void func3(int suraj[2][2])
{
    for(int i = 0; i < 2; i++)
    {

        for(int j = 0; j < 2; j++)

        {
            printf("The value at %d,%d is %d\n",i,j,suraj[i][j]);

        }

    }


}

int main()
{   int arr3[][2] = {{45,35},{78,79}};
    // int arr[] = {2,3,5,6,8};
    // int arr2[] = {4,5,6,7,9};
    // printf("The value at index 0 is %d\n",arr[0]);
    // func1(arr);
    // printf("The value at index 0 is %d\n",arr[0]);
    // func2(arr2);
    // func2(arr2);
    func3(arr3);

    return 0;
}

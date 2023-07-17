#include <stdio.h>
void arrayRev(int array[])
{
    int temp;
    for(int i = 0; i < 4; i++)
    {
        temp = array[i];
        array[i] = array[7-i];
        array[7-i] = temp;

    }

}


void printarr(int arr[])
{
    for(int i = 0; i < 8; i++)
    {
        printf("The value of array at position no %d is %d\n",i, arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    printf("Before reversing the array\n");
    printarr(arr);
    arrayRev(arr);
    printf("After reversing the array\n");
    printarr(arr);



    return 0;
}

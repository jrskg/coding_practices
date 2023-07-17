#include <stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {3,5,2,5,7,9,12,455,1,456,22};
    int size  = sizeof(arr)/sizeof(int);
    int element;
    printf("Enter the element you want to search\n");
    scanf("%d",&element);
    int index = linearSearch(arr, size, element);
    if(index == -1)
    {
        printf("Sorry this element doesn't exist");
    }
    else
    {
        printf("The %d element is found at %dth index.", element, index);
    }
    return 0;
}

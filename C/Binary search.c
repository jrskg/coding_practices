#include <stdio.h>

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == element)
        {
            return mid;
        }
        if(arr[mid]<element)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {3,5,7,9,11,12,22,55,121,156,222};
    int size  = sizeof(arr)/sizeof(int);
    int element;
    printf("Enter the element you want to search\n");
    scanf("%d",&element);
    int index = binarySearch(arr, size, element);
    if(index == -1)
    {
        printf("Sorry this element doesn't exist");
    }
    else
    {
        printf("The element %d is found at %dth index.", element, index);
    }
    return 0;
}

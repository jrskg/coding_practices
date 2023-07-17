#include <stdio.h>

int maxElement(int array[], int n)
{
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        if(array[i]>max)
        {
            max = array[i];
        }
    }
    return max;
}

int main()
{
    int arr[] = {125,366,751,61775,56561};
    int max = maxElement(arr,5);
    printf("The largest element of the array is %d\n",max);
    return 0;
}

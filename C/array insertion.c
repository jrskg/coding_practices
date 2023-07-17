#include <stdio.h>

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int size, int index, int element, int capacity)
{
    if(size >= capacity)
    {
        return -1;
    }
    for(int i = size - 1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[50] = {1, 12, 22, 25, 30};
    int size = 5, index = 3, element = 23;
    display(arr, size);
    insert(arr, size, index, element, 50);
    size += 1;
    display(arr, size);

    return 0;
}

#include <stdio.h>

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Delete(int arr[], int size, int index)
{

    for(int i = index; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }

}

int main()
{
    int arr[50] = {1, 12, 22, 25, 30};
    int size = 5, index = 1;
    display(arr, size);
    Delete(arr, size, index);
    size -= 1;
    display(arr, size);

    return 0;
}

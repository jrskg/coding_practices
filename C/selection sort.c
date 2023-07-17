#include<stdio.h>

void Display(int *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n\n");
}

void arraySort(int* A, int n)
{
    int minIndex, temp;
    for(int i = 0; i < n-1; i++)
    {
        minIndex = i;
        for(int j = i+1; j < n; j++)
        {
            if(A[j] < A[minIndex])
            {
                minIndex = j;
            }
        }
        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}

int main()
{
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/4;
    Display(arr, n);
    arraySort(arr, n);
    Display(arr, n);
    return 0;
}
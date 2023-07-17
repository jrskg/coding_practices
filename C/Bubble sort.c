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
    int isSorted = 0;
    for(int i = 0; i < n; i++)
    {
        isSorted = 1;
        printf("Working on pass no %d\n", i+1);
        for(int j = 0; j < n-1-i; j++)
        {
            if(A[j] > A[j+1])
            {
                A[j] = A[j]+A[j+1];
                A[j+1] = A[j] - A[j+1];
                A[j] = A[j] - A[j+1];
                isSorted = 0;
            }
        }
        if(isSorted)
        {
            return;
        }
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
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
    int key, j;
    for(int i = 1; i < n; i++)
    {
        key = A[i];
        j = i-1;
        while(j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main()
{
    int arr[] = {5, 80, 34, 67, 20, 48, 56};
    int n = sizeof(arr)/4;
    Display(arr, n);
    arraySort(arr, n);
    Display(arr, n);
    return 0;
}
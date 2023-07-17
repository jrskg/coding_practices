#include <stdio.h>
#include <stdlib.h>

typedef struct Array
{
    int total_size;
    int used_size;
    int *ptr;
} ArrayADTs;

void creatArray(ArrayADTs *arr, int tSize, int uSize)
{
    arr->total_size = tSize;
    arr->used_size = uSize;
    arr->ptr = (int *)malloc(tSize * sizeof(int));
}

void showArray(ArrayADTs *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("%d ", (arr->ptr)[i]);
    }
    printf("\n");
}

void setVal(ArrayADTs *arr)
{
    int n, size;
    printf("How many numbers you want to store : ");
    scanf("%d", &size);

    if (size > arr->total_size)
    {
        printf("Oops!!! Not possible");
    }
    else
    {
        arr->used_size = size;
        for (int i = 0; i < arr->used_size; i++)
        {
            printf("Enter value %d : ", i + 1);
            scanf("%d", &n);
            (arr->ptr)[i] = n;
        }
    }
}

void insert(ArrayADTs *arr, int element, int index){
    if (arr->used_size >= arr->total_size){
       printf("Insertion failed due to insufficient storage !!\n");
    }
    else{
        for (int i = arr->used_size-1; i >= index; i--)
        {
            (arr->ptr)[i+1] = (arr->ptr)[i];
        }
        (arr->ptr)[index] = element;
        arr->used_size +=1;
        printf("Insertion succeed!!\n");
    }   
}

void delete(ArrayADTs *arr, int index){
    if (arr->used_size == 0){
       printf("Nothing to delete !!\n");
    }
    else{
        for (int i = index; i < arr->used_size-1; i++)
        {
            (arr->ptr)[i] = (arr->ptr)[i+1];
        }
        arr->used_size -=1;
        printf("Deletion succeed!!\n");
    }
    
}

int main()
{
    ArrayADTs myArr;
    creatArray(&myArr, 20, 0);
    setVal(&myArr);
    showArray(&myArr);
    delete(&myArr, 0);
    showArray(&myArr);

    return 0;
}
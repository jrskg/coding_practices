#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct queue* ptr)
{
    if(ptr->r == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue* ptr)
{
    if(ptr->r == ptr->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue* ptr, int val)
{
    if(isFull(ptr))
    {
        printf("The queue is full\n");
    }
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = val;
    }
}

int dequeue(struct queue* ptr)
{
    int a = -1;
    if(isEmpty(ptr))
    {
        printf("The queue is empty\n");
    }
    else
    {
        ptr->f++;
        a = ptr->arr[ptr->f];
    }
    return a;
}

int main()
{
    struct queue ms;
    ms.size = 50;
    ms.f = -1;
    ms.r = -1;
    ms.arr = (int*)malloc(ms.size * sizeof(int));
    enqueue(&ms, 15);
    enqueue(&ms, 14);
    enqueue(&ms, 12);
    enqueue(&ms, 19);
    enqueue(&ms, 10);

    return 0;
}
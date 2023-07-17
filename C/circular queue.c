#include<stdio.h>
#include<stdlib.h>

struct CircularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct CircularQueue* ptr)
{
    if((ptr->r+1)%ptr->size == ptr->f)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct CircularQueue* ptr)
{
    if(ptr->r == ptr->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct CircularQueue* ptr, int val)
{
    if(isFull(ptr))
    {
        printf("The queue is full\n");
    }
    else
    {
        ptr->r = (ptr->r+1)%ptr->size;
        ptr->arr[ptr->r] = val;
        printf("Queued element %d\n",val);
    }
}

int dequeue(struct CircularQueue* ptr)
{
    int a = -1;
    if(isEmpty(ptr))
    {
        printf("The queue is empty\n");
    }
    else
    {
        ptr->f = (ptr->f+1)%ptr->size;
        a = ptr->arr[ptr->f];
    }
    return a;
}

int main()
{
    struct CircularQueue ms;
    ms.size = 6;
    ms.f = 0;
    ms.r = 0;
    ms.arr = (int*)malloc(ms.size * sizeof(int));
    enqueue(&ms, 15);
    enqueue(&ms, 14);
    enqueue(&ms, 12);
    enqueue(&ms, 19);
    enqueue(&ms, 10);
    printf("Dequeued element %d\n",dequeue(&ms));
   
    return 0;
}
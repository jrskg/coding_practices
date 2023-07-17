#include<stdio.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct queue* ptr)
{
    if(ptr->r == ptr->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue* ptr)
{
    if(ptr->r == ptr->size-1)
    {
        return 1;
    }
    return 0;
}

void enqueueR(struct queue* ptr, int element)
{
    if(isFull(ptr))
    {
        printf("The queue is full\n");
    }
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = element;
        printf("Element %d enqueued to rear successfully\n", element);
    }
}

int dequeueF(struct queue* ptr)
{
    if(isEmpty(ptr))
    {
        printf("The queue is empty\n");
    }
    else
    {
        ptr->f++;
        return ptr->arr[ptr->f];
    }
}

void enqueueF(struct queue* ptr, int element)
{
    if(ptr->f == -1)
    {
        printf("Sorry you cannot enqueue here\n");
    }
    else
    {
        ptr->arr[ptr->f] = element;
        ptr->f--;
        printf("Element %d enqueued to front successfully\n", element);
    }
}

int dequeueR(struct queue* ptr)
{
    int val;
    if(isEmpty(ptr))
    {
        printf("The queue is empty");
    }
    else
    {
        val = ptr->arr[ptr->r];
        ptr->r--;
    }
    return val;
}


int main()
{
    struct queue ms;
    ms.size = 20;
    ms.f = -1;
    ms.r = -1;
    ms.arr = (int*)malloc(ms.size * sizeof(int));

    enqueueR(&ms, 4);
    enqueueR(&ms, 3);
    enqueueR(&ms, 6);
    enqueueR(&ms, 5);
    dequeueF(&ms);
    enqueueF(&ms, 67);
    dequeueR(&ms);
    printf("%d  %d\n",ms.r, ms.f);//for checking the changing value of front and rear during enquing and dequing

    return 0;
}
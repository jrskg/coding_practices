#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node * next;
};

struct node* f = NULL;
struct node* r = NULL;

void Traversal()
{
    while(f != NULL)
    {
        printf("Element:%d\n", f->data);
        f = f->next;
    }
}

void enqueue(int element)
{
    struct node * n = (struct node*)malloc(sizeof(struct node));
    if(n == NULL)
    {
        printf("The queue is full\n");
    }
    else
    {
        n->data = element;
        n->next = NULL;
        if(f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct node * ptr = f;
    if(f == NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    enqueue(45);
    enqueue(47);
    enqueue(49);
    enqueue(25);
    Traversal();
    return 0;
}
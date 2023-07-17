#include<stdio.h>

struct node
{
    int data;
    struct node * next;
};

void Traversal(struct node * ptr)
{
    while(ptr != NULL)
    {
        printf("Elements are:%d\n",ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct node * top)
{
    if(top == NULL)
    {
        return 1;
    }

    return 0;
}

int isFull(struct node * top)
{
    struct node * p = (struct node *)malloc(sizeof(struct node));
    if(p == NULL)
    {
        return 1;
    }

    return 0;
}

struct node* push(struct node * top, int element)
{
    if(isFull(top))
    {
        printf("Stack overflow\n");
    }
    else
    {
        struct node * p = (struct node *) malloc(sizeof(struct node));
        p->data = element;
        p->next = top;
        top = p;
        return top;
    }
}

struct node* pop(struct node * top)
{
    if(isEmpty(top))
    {
        printf("Stack underflow\n");
    }
    else
    {
        struct node * p = top;
        top = top->next;
        printf("The popped value is %d\n", p->data);
        free(p);
        return top;
    }
}

void peek(struct node * top, int pos)
{
    struct node * ptr = top;
    for(int i = 0; (i < pos-1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }

    if(ptr != NULL)
    {
        printf("The element at position no.%d is %d\n",pos, ptr->data);
    }
    else
    {
        printf("Sorry this element doesn't exist..\n");
    }
}

int main()
{
    struct node * top = NULL;
    top = push(top, 44);
    top = push(top, 45);
    top = push(top, 46);
    top = push(top, 47);

    Traversal(top);
    peek(top, 2);
    return 0;
}
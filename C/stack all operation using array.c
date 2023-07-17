#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack * ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack * ptr)
{
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack * ptr, int n)
{
    if(isFull(ptr))
    {
        printf("Stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = n;
        printf("Push operation completed successfully\n");
    }
}

int pop(struct stack * ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack underflow\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return val;
    }
}

int Peek(struct stack * ptr, int i)
{
    if(ptr->top - i + 1 < 0)
    {
        printf("Error! Not a valid position..\n");
    }
    else if(ptr->top-i+1 > ptr->top)
    {
        printf("Sorry! this element doesn't exist\n");
    }
    else
    {
        return ptr->arr[ptr->top-i+1];
    }
}

int topMost(struct stack * m)
{
    return m->arr[m->top];
}

int buttomMost(struct stack * m)
{
    return m->arr[0];
}

int main()
{
    struct stack * m = (struct stack *)malloc(sizeof(struct stack));
    m->size = 10;
    m->top = -1;
    m->arr = (int *)malloc(m->size * sizeof(int));

    while(1)
    {
        int access;
        printf("\nWhat do you want to do ?\n1.Push operation\n2.Pop operation\n3.Peek operation\n4.See topmost element\n5.See buttom most element\n6.Exit\n");
        scanf("%d", &access);

        if(access == 1)
        {
            int n;
            printf("Enter the element you want to push\n");
            scanf("%d", &n);
            push(m, n);
        }
        else if(access == 2)
        {
            int PopedVal = pop(m);
            printf("The poped element is %d\n", PopedVal);
        }
        else if(access == 3)
        {
            int i;
            printf("1.Peek all element\n2.Peek one element\n");
            scanf("%d", &i);

            if(i == 1)
            {
                for(int j = 1; j < m->top + 2; j++)
                {
                    printf("Element at position no.%d is %d\n", j, Peek(m, j));
                }
            }
            else if(i == 2)
            {
                int ind;
                printf("Enter the position no:\n");
                scanf("%d", &ind);
                printf("Element at position no.%d is %d\n", ind, Peek(m, ind));
            }
            else
            {
                printf("Wrong input\n");
            }
        }
        else if(access == 4)
        {
            printf("The top most element is %d\n", topMost(m));
        }
        else if(access == 5)
        {
            printf("The buttom most element is %d\n", buttomMost(m));
        }
        else if(access == 6)
        {
            printf("Program terminated..\n");
            break;
        }
        else
        {
            printf("Wrong input\n");
        }
    }
    return 0;
}
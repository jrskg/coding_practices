#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char * arr;
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

void push(struct stack * ptr, char c)
{
    if(isFull(ptr))
    {
        printf("Stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = c;
    }
}

char pop(struct stack * ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack underflow\n");
    }
    else
    {   char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int match(char a, char b)
{
    if(a == '(' && b == ')' || a == '{' && b =='}' || a == '[' && b ==']')
    {
        return 1;
    }
    return 0;
}

int paranthesisCheck(char * exp)
{
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 20;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char val;

    for(int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(sp, exp[i]);
        }
        else if(exp[i] == ')'|| exp[i] == ']' || exp[i] == '}')
        {
            if(isEmpty(sp))
            {
                return 0;
            }
            val = pop(sp);
            if(!match(val, exp[i]))
            {
                return 0;
            }
        }
    }
    if(isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char exp[36];
    printf("Enter the expression to check.\n");
    gets(exp);
    if(paranthesisCheck(exp))
    {
        printf("Paranthesis is balanced\n");
    }
    else
    {
        printf("Paranthesis is not balanced\n");
    }
    return 0;
}
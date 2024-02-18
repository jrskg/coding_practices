#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int *arr;
    int size;
    int top;
};
typedef struct Stack stack;

stack* initStack(int size){
    stack * newStack = (stack*)malloc(sizeof(stack*));
    newStack->arr = (int*)malloc(size*sizeof(int*));
    newStack->size = size;
    newStack->top = -1;

    return newStack;
}

int isEmpty(stack* st){
    return st->top == -1;
}

int isFull(stack* st){
    return st->top == st->size-1;
}

void push(stack* st, int data){
    if(isFull(st)){
        printf("\nStack overflow\n\n");
        return;
    }

    st->top = st->top + 1;
    st->arr[st->top] = data;
}

void pop(stack* st){
    if(isEmpty(st)){
        printf("\nStack underflow\n\n");
        return;
    }

    int data = st->arr[st->top];
    st->top = st->top - 1;
    printf("\nPopped element : %d\n\n", data);
}

int peek(stack* st){
    if(isEmpty(st)){
        printf("\nStack underflow\n\n");
        return -1;
    }
    return st->arr[st->top];
}

void traverse(stack* st){
    if(isEmpty(st)){
        printf("\nStack underflow\n\n");
        return;
    }
    printf("\nThe stack is : ");
    for(int i = st->top; i >= 0; i--){
        printf("%d ", st->arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter stack size : ");
    scanf("%d", &size);
    stack * myStack = initStack(size);

    int choice, data;
    while(choice != 7){
        printf("\n1.Push\n2.Pop\n3.Check Empty\n4.Check Full\n5.Check Peek\n6.Traverse\n7.To Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data : ");
                scanf("%d", &data);
                push(myStack, data);
                break;

            case 2:
                pop(myStack);
                break;

            case 3:
                int empty = isEmpty(myStack);
                if(empty){
                    printf("\nStack is empty\n\n");
                }else{
                    printf("\nStack is not empty\n\n");
                }
                break;

            case 4:
                int full = isFull(myStack);
                if(full){
                    printf("\nStack is Full\n\n");
                }else{
                    printf("\nStack is not full\n\n");
                }
                break;

            case 5:
                int pElem = peek(myStack);
                printf("\nPeek element : %d\n\n", pElem);
                break;

            case 6:
                traverse(myStack);
                break;

            case 7:
                printf("\nThanks for using :)\n\n");
                free(myStack->arr);
                free(myStack);
                break;

            default:
                printf("\nInvalid input\n\n");
        }
    }

    return 0;
}
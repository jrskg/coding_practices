#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>

struct Stack{
    char *arr;
    int size;
    int top;
};
typedef struct Stack stack;

stack* initStack(int size){
    stack * newStack = (stack*)malloc(sizeof(stack*));
    newStack->arr = (char*)malloc(size*sizeof(char*));
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

void push(stack* st, char data){
    if(isFull(st)){
        return;
    }

    st->top = st->top + 1;
    st->arr[st->top] = data;
}

void pop(stack* st){
    if(isEmpty(st)){
        return;
    }

    st->top = st->top - 1;
}

char peek(stack* st){
    if(isEmpty(st)){
        return '\0';
    }
    return st->arr[st->top];
}

int precedence(char ch){
    if(ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return 1;
}

void infixToPostfix(char* infix){
    printf("\n");
    int len = strlen(infix);
    stack* st = initStack(len);
    char postfix[50];
    int i = 0, p = 0;

    while(i < len){
        if(isalpha(infix[i])){
            postfix[p++] = infix[i]; 

        }
        else if(infix[i] == '('){
            push(st, infix[i]);
        }
        else{
            if(infix[i] == ')'){
                while(!isEmpty(st) && peek(st) != '('){
                    postfix[p++] = peek(st);
                    pop(st);
                }
                pop(st);
            }else{
                while(!isEmpty(st) && peek(st) != '(' && precedence(infix[i]) <= precedence(peek(st))){
                    postfix[p++] = peek(st);
                    pop(st);
                }
                push(st, infix[i]);
            }
        }
        i++;
    }

    while(!isEmpty(st)){
        postfix[p++] = peek(st);
        pop(st);
    }
    postfix[p] = '\0';

    p = 0;
    while(postfix[p] != '\0'){
        printf("%c",postfix[p++]);
    }
    printf("\n\n");
    free(st->arr);
    free(st);
}

void infixToPrefix(char* infix){
    printf("\n");
    int len = strlen(infix);
    stack* st = initStack(len);
    char prefix[50];
    int p = 0;

    for(int i = len-1; i >= 0; i--){
        if(isalpha(infix[i])){
            prefix[p++] = infix[i]; 
        }
        else if(infix[i] == ')'){
            push(st, infix[i]);
        }
        else{
            if(infix[i] == '('){
                while(!isEmpty(st) && peek(st) != ')'){
                    prefix[p++] = peek(st);
                    pop(st);
                }
                pop(st);
            }else{
                while(!isEmpty(st) && peek(st) != ')' && precedence(infix[i]) < precedence(peek(st))){
                    prefix[p++] = peek(st);
                    pop(st);
                }
                push(st, infix[i]);
            }
        }
    }

    while(!isEmpty(st)){
        prefix[p++] = peek(st);
        pop(st);
    }
    prefix[p] = '\0';

    int s = 0, e = p-1;
    while(s <= e){
        char temp = prefix[s];
        prefix[s] = prefix[e];
        prefix[e] = temp;
        s++;
        e--;
    }

    p = 0;
    while(prefix[p] != '\0'){
        printf("%c",prefix[p++]);
    }
    printf("\n\n");
    free(st->arr);
    free(st);
}


int main() {
    char str[50];
    printf("Enter infix : ");
    scanf("%s", str);
    infixToPostfix(str);
    infixToPrefix(str);
    return 0;
}
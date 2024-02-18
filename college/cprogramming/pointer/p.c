#include <stdio.h>
void swapRef(int *, int *);
void swapVal(int , int );

int main() {
    int a = 10, b = 20;

    printf("\n\nThis is for pass by value\n");
    printf("Before swapping\n");
    printf("a : %d   b : %d\n", a, b);
    swapVal(a, b);
    printf("After swapping\n");
    printf("a : %d   b : %d\n", a, b);


    printf("\n\nThis is for pass by reference\n");
    printf("Before swapping\n");
    printf("a : %d   b : %d\n", a, b);
    swapRef(&a, &b);
    printf("After swapping\n");
    printf("a : %d   b : %d\n", a, b);
    return 0;
}
void swapRef(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapVal(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

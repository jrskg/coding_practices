#include <stdio.h>
void passByVal(int, int);
void passByRef(int*, int*);

int main() {
    int a = 10, b = 20;

    printf("For pass by value a, b before function call\n");
    printf("a ---> %d\tb ---> %d\n", a, b);
    passByVal(a, b);
    printf("For pass by value a, b after function call\n");
    printf("a ---> %d\tb ---> %d\n", a, b);

    printf("\nFor pass by reference a, b before function call\n");
    printf("a ---> %d\tb ---> %d\n", a, b);
    passByRef(&a, &b);
    printf("For pass by reference a, b after function call\n");
    printf("a ---> %d\tb ---> %d\n", a, b);
    
    return 0;
}

void passByVal(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void passByRef(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
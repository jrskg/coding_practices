#include <stdio.h>

int main() {
    int a, b, *c;
    a = 10;
    b = a;
    c = &a;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("value c = %d\n", *c);
    
    a = a*10;
    
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("value c = %d\n", *c);
    return 0;
}
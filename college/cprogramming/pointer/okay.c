#include <stdio.h>

int main() {
    int a;
    int *p = &a;
    printf("Enter a number : ");
    scanf("%d", p);

    printf("The number is %d\n", a);
    printf("The number is %d\n", *p);
    return 0;
}
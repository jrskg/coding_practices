#include <stdio.h>

int main() {
    char a;
    printf("Enter the variable ");
    scanf("%c", &a);
    printf("The ASCII value of %c is %d\n",a,(int)a);
    return 0;
}
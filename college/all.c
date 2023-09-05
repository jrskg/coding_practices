#include<stdio.h>

int main(){
    int ch;
    int a, b;
    printf("1 for Add\n2 for Subtract\n3 for Multiply\n4 for Divide\n : ");
    scanf("%d", &ch);
    printf("Numbers : ");
    scanf("%d%d", &a,&b);

    switch (ch){
    case 1:
        printf("%d + %d = %d", a, b, a+b);
        break;
    case 2:
        printf("%d - %d = %d", a, b, a-b);
        break;
    case 3:
        printf("%d * %d = %d", a, b, a*b);
        break;
    case 4:
        printf("%d / %d = %d", a, b, a/b);
        break;
    default:
        printf("Invalid input");
        break;
    }
}
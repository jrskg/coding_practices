#include<stdio.h>

int main(){
    char ch;
    int a, b;
    printf("Operator : ");
    scanf("%c", &ch);
    printf("Numbers : ");
    scanf("%d%d", &a,&b);

    switch (ch){
    case '+':
        printf("%d + %d = %d", a, b, a+b);
        break;
    case '-':
        printf("%d - %d = %d", a, b, a-b);
        break;
    case '*':
        printf("%d * %d = %d", a, b, a*b);
        break;
    case '/':
        printf("%d / %d = %d", a, b, a/b);
        break;
    default:
        printf("Invalid invalid input");
        break;
    }
}
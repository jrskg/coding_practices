#include<stdio.h>

void suraj(int* c, int* d)
{
    int x, y;
    x = *c + *d;
    *c = x;
    y = (x - *d) - *d;
    *d = y;

    return;
}

int main()
{
    int a, b;
    printf("Enter a number\n");
    scanf("%d",&a);
    printf("Enter the second number\n");
    scanf("%d",&b);
    suraj(&a,&b);
    printf("The addition is %d\nThe subtraction is %d\n",a,b);


    return 0;
}
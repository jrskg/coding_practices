#include <stdio.h>

int sum(int a, int b)
{
    return a+b;
}

int main()
{
    int(*fptr) (int, int);
    fptr = &sum;
    int d = (*fptr)(2,3);
    printf("The value of d is %d\n",d);
    return 0;
}

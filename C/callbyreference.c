#include <stdio.h>

void swap(int*num,int*num2)
{
    int c;
    c = *num;
    *num = *num2;
    *num2 = c;
    return;


}

int main()
{
    int a = 35,b = 40;
    printf("%d and %d\n",a,b);
    swap(&a,&b);
    printf("%d and %d\n",a,b);
    return 0;
}


#include <stdio.h>

int main()
{
    int*ptr2=NULL;
    int a = 76;
    int*ptra = &a;

    printf("The address of some garbage is %p\n",ptr2);
    printf("The address of pointer to a is %p\n",&ptra);
    printf("The value of a is %d\n",*ptra);
    printf("The value of a is %d\n",a);
    printf("The address of a is %p\n",&a);
    printf("The address of a is %p\n",ptra);
    
    
    return 0;
}

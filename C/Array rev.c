#include <stdio.h>

void revArray(int mul[], int n)
{
    int temp;
    for(int i = 0; i < n/2; i++)
    {   
        temp = mul[i];
        mul[i] = mul[n-i-1];
        mul[n-i-1] = temp;
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ",mul[i]);
    }
}

int main()
{
    int n;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int mul[n];
    printf("Enter the element or array\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&mul[i]);
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ",mul[i]);
    }
    printf("\n");
    revArray(mul, n);
    return 0;
}

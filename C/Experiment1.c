#include<stdio.h>

int add(int a,int b)
{
    return a+b;
  
}

int main()
{

    int x,y;
    printf("Enter the first number\n");
    scanf("%d",&x);
    
    printf("Enter the second number\n");
    scanf("%d",&y);
    
    int s = add(x,y);
    
    printf("The value of s is %d\n",s);
    
    

    return 0;
}

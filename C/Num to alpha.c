#include<stdio.h>

int main()
{ 
    char c;
    printf("Enter your letter\n");
    scanf("%c",&c);
    int n = (int)c;
    printf("%d\n",n);
    
    int b;
    
     printf("Enter your number\n");
     scanf("%d",&b);  
     char v = (char)b;
     printf("%c\n", v);
    
    return 0;
}
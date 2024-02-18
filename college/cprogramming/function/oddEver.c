#include <stdio.h>
int isOdd(int);

int main() {
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    if(isOdd(n)){
        printf("%d is odd number\n", n);
    }else{
        printf("%d is even number\n", n);
    }
    
    return 0;
}

int isOdd(int a){
    return a % 2;
}
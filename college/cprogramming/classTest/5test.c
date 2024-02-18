#include <stdio.h>

int isOdd(int);

int main() {
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    if(isOdd(num)){
        printf("%d is odd number\n", num);
    }else{
        printf("%d is even number\n", num);
    }
    return 0;
}

int isOdd(int n){
    return n%2;
}
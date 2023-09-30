#include <stdio.h>
int fib(int);

int main() {
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    int fibN = fib(n);
    printf("The %dth fib number is : %d\n", n, fibN);
    return 0;
}

int fib(int n){
    if(n == 1 || n == 0){
        return n;
    }
    return fib(n-1) + fib(n-2);
}
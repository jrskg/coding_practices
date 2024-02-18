#include<stdio.h>

int main(){
    int sum = 0;
    for(int i = 100; i <= 200; i++){
        sum += i;
    }
    printf("The sum is %d\n", sum);
    return 0;
}
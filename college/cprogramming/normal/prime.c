#include <stdio.h>

int main() {
    int num = 2, count = 0;
    printf("The first 10 prime numbers are : \n");
    while(count < 10){
        int prime = 1;
        for(int i = 2; i*i <= num; i++){
            if(num%i == 0){
                prime = 0;
                break;
            }
        }
        if(prime){
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
    return 0;
}
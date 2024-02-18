#include<stdio.h>

int main(){
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);

    for(int i = num; i > 0; i--){
        for(int j = 0; j < i; j++){
            printf("%d", i);
        }
        printf("\n");
    }

    printf("\n");

    for(int i = num; i > 0; i--){
        for(int j = 0; j < i; j++){
            printf("%d", j+1);
        }
        printf("\n");
    }
    printf("\n");
    int c = 1;
    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= i; j++){
            printf("%d", c%2);
            c++;
        }
        printf("\n");
    }

    return 0;
}
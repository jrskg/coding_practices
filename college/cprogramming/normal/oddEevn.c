#include<stdio.h>

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        if(i&1){
            printf("%d", i);
        }else{
            printf("\t%d\n", i);
        }
    }

    return 0;
}
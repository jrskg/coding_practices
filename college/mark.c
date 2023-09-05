#include<stdio.h>

int main(){
    int mark;
    printf("Enter mark: ");
    scanf("%d", &mark);

    if(mark > 35){
        printf("Pass\n");
    }else{
        printf("Fail\n");
    }
    return 0;
}
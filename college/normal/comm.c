#include<stdio.h>
int main(){
    int sales, com;
    printf("Enter sales amount : ");
    scanf("%d", &sales);

    if(sales >= 1000){
        com = (sales*10)/100;
    }else{
        com = (sales*5)/100;
    }

    printf("Commission amount is Rs.%d\n", com);

    return 0;

}
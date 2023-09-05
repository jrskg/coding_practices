#include<stdio.h>
int main(){
    float sales, com;
    printf("Enter sales amount : ");
    scanf("%f", &sales);

    if(sales >= 10000){
        com = (sales*15)/100;
    }
    else if(sales >= 1000 && sales < 10000){
        com = (sales*10)/100;
    }
    else{
        com = (sales*5)/100;
    }

    printf("Commission amount is Rs.%.2f\n", com);
    return 0;
}
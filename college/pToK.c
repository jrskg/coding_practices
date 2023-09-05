#include<stdio.h>


int main(){
    double p,k;
    printf("enter the value in kilogram: ");
    scanf("%lf",&k);
    p=k*2.2;
    printf("%lf kilogram into %lf pound\n", k,p);

    return 0;
}
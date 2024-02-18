#include<stdio.h>

int main(){
    int a, b, c;
    printf("Enter a , b and c : ");
    scanf("%d%d%d", &a, &b, &c);

    if( a > b && a > c){
        printf("a is greatest\n");
    }else if( b > c){
        printf("b is greatest\n");
    }else{
        printf("c is greatest\n");
    }

    int m, n;
    printf("Enter m and n : ");
    scanf("%d%d", &m, &n);
    if(m>n){
        printf("m is greater\n");
    }else{
        printf("n is greater\n");
    }

    return 0;
}
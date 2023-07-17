#include<stdio.h>

void recFunc1(int n){
    if(n == 0) return;
    printf("%d\n", n);
    recFunc1(n-1);
    printf("%d\n", n);
    return;
}

// int sumRec(int n, int c){
//     if(n==0) return c;
//     return sumRec(n-1, c+n);
// }

int sumRec(int n){
    if(n==0){
        return 0;
    }
    return n+sumRec(n-1);
}

int calcPowerRec(int num, int pow){
    if(pow == 0){
        return 1;
    }
    return num*calcPowerRec(num, pow-1);
}

int fibRec(int n){
    if(n<=2){
        return 1;
    }
    return fibRec(n-1)+fibRec(n-2);
}

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    // recFunc1(n);
    // printf("%d\n", sumRec(n));
    // printf("%d\n", calcPowerRec(n, 3));
    printf("%d\n", fibRec(n));

    return 0;
}
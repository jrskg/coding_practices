#include<stdio.h>
int main(){
    int a = 0, b = 1, ans;
    printf("%d " , b);
    do{
        ans = a+b;
        a = b;
        b = ans;
        printf("%d ", ans);
    }while(ans < 13);
    printf("\n");
    return 0;
}


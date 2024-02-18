#include<stdio.h>

int reverse(int, int);

int main(){
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    int rev = reverse(num, 0);
    printf("The reverse is %d\n", rev);
    return 0;
}

int reverse(int num, int ans){
    if(num == 0){
        return ans;
    };
    int digit = num%10;
    return reverse(num/10, ans*10+digit);
}
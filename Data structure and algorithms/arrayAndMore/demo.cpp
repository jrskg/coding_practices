#include<iostream>
#include <string>
#include<math.h>
using namespace std;

void decimalToBinary(){
    int n;
    string ans = "";
    cout<<"Enter a number : "<<endl;
    cin>>n;
    for(int i = 0; n != 0; i++){
        int bit = n & 1;
        ans = to_string(bit) + ans;
        n = n >> 1;
    }
    cout<<"Binary number is : "<<ans<<endl;
}

void binaryToDecimal(){
    int decimalInInt, ans = 0, i = 0;
    cout<<"Enter a binary number : "<<endl;
    cin>>decimalInInt;

    while (decimalInInt != 0){
        int digit = decimalInInt % 10;
        if(digit == 1)
            ans += pow(2, i);
        i++;
        decimalInInt = decimalInInt / 10;
    }
    cout<<"Decimal number is : "<<ans<<endl;
}

void bitwiseComplement(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;

    if(n == 0){
        cout<<"Binary complement is : 1"<<endl;
        return;
    }
    int mask = 0, m = n;
    while( m != 0){
        m = m >> 1;
        mask = (mask << 1)|1;
    }

    int ans = (~n) & mask;
    cout<<"Binary complement is : "<<ans<<endl;
}

//college
float cToF(float c){
    return (c*1.8)+32;
}

void fib(int num){
    int a = 0, b = 1, i = 0, ans = a+b;
    do{
        cout<<ans<<" ";
        a = b;
        b = ans;
        ans = a+b;
    }while(++i < num);
}

void palindrome(int num){
    int org = num, rev = 0;
    while(num){
        rev = (rev*10) + (num%10);
        num = num/10;
    }
    if(rev == org)
        cout<<org<<" is a palindrome"<<endl;
    else
        cout<<org<<" is not a palindrome"<<endl;
}

int fact(int num){
    if(num < 0){
        cout<<"Number can't be a negative number"<<endl;
        return -1;
    }
    int ans = 1;
    for(int i = 1; i <= num; i++){
        ans *= i;
    }
    return ans;
}

int main(){
    // decimalToBinary();
    // binaryToDecimal();
    // bitwiseComplement();
    // cout<<cToF(100)<<endl;
    // fib(10);
    // palindrome(122);
    // cout<<fact(0)<<endl;
    return 0;
}
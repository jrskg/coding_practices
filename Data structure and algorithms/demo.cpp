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

int main(){
    // decimalToBinary();
    // binaryToDecimal();
    bitwiseComplement();
    return 0;
}
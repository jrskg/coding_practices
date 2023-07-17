#include<iostream>
#include<algorithm>
using namespace std;

string addBinary(int bNum1, int bNum2){
    string result = "";
    int carry = 0;

    while (bNum1 != 0 || bNum2 != 0){
        if(bNum1 % 2 == 0 && bNum2 % 2 == 0){
            result += to_string(carry);
            carry = 0;
        }else if((bNum1 % 2 == 0 && bNum2 % 2 == 1) || (bNum1 % 2 == 1 && bNum2 % 2 == 0)){
            if(carry == 1){
                result += to_string(0);
                carry = 1;
            }else{
                result += to_string(1);
                carry = 0;
            }
        }else{
            if(carry == 1){
                result += to_string(1);
            }else{
                result += to_string(0);
            }
            carry = 1;
        }
        bNum1 = bNum1/10;
        bNum2 = bNum2/10;
    }

    while (bNum1 != 0){
        if(carry == 1){
            if(bNum1 % 2 == 1){
                result += to_string(0);
                carry = 1;
            }else{
                result += to_string(1);
                carry = 0;
            }
        }else{
            result += to_string(bNum1 % 2);
        }
        bNum1 = bNum1/10;
    }

    while (bNum2 != 0){
        if(carry == 1){
            if(bNum2 % 2 == 1){
                result += to_string(0);
                carry = 1;
            }else{
                result += to_string(1);
                carry = 0;
            }
        }else{
            result += to_string(bNum2 % 2);
        }
        bNum2 = bNum2/10;
    }
    
    if(carry == 1){
        result += to_string(1);
    }
    reverse(result.begin(), result.end());
    return result;
} 

int main(){
    int a, b;
    cout<<"Enter two binary number to sum "<<endl;
    cin>>a>>b;

    cout<<"The added binary is : "<<addBinary(a, b)<<endl;
   
    return 0;
}
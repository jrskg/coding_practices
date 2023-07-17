#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

void pythagoreanTriplet(){
    int a, b, c;
    cout<<"Enter three numbers\n";
    cin>>a>>b>>c;

    int x, y, z;
    x = max(a, max(b, c));

    if(x == a){
        y = b;
        z = c;
    }else if(x == b){
        y = a;
        z = c;
    }else{
        y = a;
        z = b;
    }

    if(x*x == y*y + z*z){
        cout<<"Its a pythagorean triplet"<<endl;
    }else{
        cout<<"Not a pythagorean triplet"<<endl;
    }
}

void binaryToDecimal(){
    int n, i = 0, rem, ans = 0; 
    cout<<"Enter a binary number : ";
    cin>>n;
    int binary = n;
    while (n){
        rem = n%10;
        ans += rem * round(pow(2, i));
        n = n/10;
        i++;
    }

    cout<<"Binary ("<<binary<<") = "<<ans<<" in decimal"<<endl;
}

void octalToDecimal(){
    int n, i = 0, rem, ans = 0; 
    cout<<"Enter a octal number : ";
    cin>>n;
    int octal = n;
    while (n){
        rem = n%10;
        ans += rem * round(pow(8, i));
        n = n/10;
        i++;
    }

    cout<<"Octal ("<<octal<<") = "<<ans<<" in decimal"<<endl;
}

void hexaDecimalToDecimal(){
    int ans = 0, power = 0; 
    string hex;
    cout<<"Enter a hexadecimal number : ";
    cin>>hex;
    int size  = hex.size();
    
    for(int i = size-1; i >= 0; i--){
        if(hex[i] >= '0' && hex[i] <= '9'){
            ans += (hex[i] - '0') * round(pow(16, power));
            power++;
        }else if(hex[i] >= 'A' && hex[i] <= 'F'){
            ans += ((hex[i] - 'A')+10) * round(pow(16, power));
            power++;
        }
    }

    cout<<"Hexadecimal ("<<hex<<") = "<<ans<<" in decimal"<<endl;
}

void decimalToBinary(){
    int n, rem; 
    string ans = "";
    cout<<"Enter a decimal number : ";
    cin>>n;
    int dec = n;

    if(n == 0){
        ans = "00";
    }else if(n == 1){
        ans = "01";
    }else{
        while (n){
            rem = n%2;
            ans = ans+to_string(rem);
            n = n/2;
        }
        reverse(ans.begin(), ans.end());
    }

    cout<<"Decimal ("<<dec<<") = "<<ans<<" in binary"<<endl;
}

void decimalToOctal(){
    int n, rem; 
    string ans = "";
    cout<<"Enter a decimal number : ";
    cin>>n;
    int dec = n;
    
    if(n == 0){
        ans = "0";
    }else{
        while (n){
            rem = n%8;
            ans = ans+to_string(rem);
            n = n/8;
        }
        reverse(ans.begin(), ans.end());
    }

    cout<<"Decimal ("<<dec<<") = "<<ans<<" in octal"<<endl;
}

void decimalToHexadecimal(){
    int n, rem; 
    string ans = "";
    cout<<"Enter a decimal number : ";
    cin>>n;
    int dec = n;
    
    if(n == 0){
        ans = "0";
    }else{
        while (n){
            rem = n%16;
            if(rem > 9){
                ans = ans+char(65+rem-10);
            }else{
                ans = ans+to_string(rem);
            }
            n = n/16;
        }
        reverse(ans.begin(), ans.end());
    }

    cout<<"Decimal ("<<dec<<") = "<<ans<<" in Hexadecimal"<<endl;
}

int reverseNumber(int n){
    int output = 0;
    while(n > 0){
        int lastDigit = n%10;
        output = output*10+lastDigit;
        n /= 10;
    }
    return output;
}
void addBinary(){
    int a, b, prevCarry = 0;
    string ans = "";
    cout<<"Enter two binary numbers\n";
    cin>>a>>b;

    while(a > 0 && b > 0){
        if(a%2 == 0 && b%2 == 0){
            ans = ans+to_string(prevCarry);
            prevCarry = 0;
        }else if((a%2 == 1 && b%2 == 0) || (a%2 == 0 && b%2 == 1)){
            if(prevCarry == 1){
                ans = ans+to_string(0);
                prevCarry = 1;
            }else{
                ans = ans+to_string(1);
                prevCarry = 0;
            }
        }else{
            ans = ans+to_string(prevCarry);
            prevCarry = 1;
        }

        a /= 10;
        b /= 10;
    }

    while (a > 0){
        if(prevCarry == 1){
            if(a%2 == 1){
                ans = ans+to_string(0);
                prevCarry = 1;
            }else{
                ans = ans+to_string(1);
                prevCarry = 0;
            }
        }else{
            ans = ans+to_string(a%2);
        }
        a /= 10;
    }

    while (b > 0){
        if(prevCarry == 1){
            if(b%2 == 1){
                ans = ans+to_string(0);
                prevCarry = 1;
            }else{
                ans = ans+to_string(1);
                prevCarry = 0;
            }
        }else{
            ans = ans+to_string(b%2);
        }
        b /= 10;
    }

    if(prevCarry == 1){
        ans = ans+to_string(1);
    }
    reverse(ans.begin(), ans.end());
    cout<<"Sum of these two binary numbers : "<<ans<<endl;
}



int main(){
    // pythagoreanTriplet();
    // binaryToDecimal();
    // octalToDecimal();
    // hexaDecimalToDecimal();
    // decimalToBinary();
    // decimalToOctal();
    // decimalToHexadecimal();
    addBinary();
    return 0;
}
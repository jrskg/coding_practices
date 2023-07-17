#include <iostream>
#include <vector>
#define m 1000000007
using namespace std;

int countPrimes(int n) {
    int count = 0;
    vector<bool> primes(n+1, true);
    primes[0] = primes[1] = false;
    for(int i = 2; i < n; i++){
        if(primes[i]){
            count++;
            for(int j = 2*i; j < n; j = j + i){
                primes[j] = false;
            }
        }
    }
    return count;
}

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    while(a % b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return b;
}

int lcm(int a, int b){
    //using relationship between lcm and gcd
    //lcm(a, b) * gcd(a, b) == a * b

    return (a * b) / gcd(a, b);
}

int fastExponentiation(int a, int b){
    int result = 1;
    while(b > 0){
        if(b & 1){
            result = result * a;
        }
        a = a * a;
        b = b >> 1;
    }
    return result;
}

int fastExponentiationMod(int a, int b){
    //used modulo arithmetic to handle large numbers
    int result = 1;
    while(b > 0){
        if(b & 1){
            result = (result * (a%m))%m;
        }
        a = ((a%m) * (a%m))%m;
        b = b >> 1;
    }
    return result;
}

int main(){
    // int num;
    // cout<<"Enter a number : ";
    // cin>>num;
    // cout<<countPrimes(num)<<endl;

    int a, b;
    cout<<"Enter any two number : ";
    cin>>a>>b;
    // cout<<gcd(a, b)<<endl;
    // cout<<lcm(a, b)<<endl;
    cout<<fastExponentiation(a, b)<<endl;
    return 0;
}
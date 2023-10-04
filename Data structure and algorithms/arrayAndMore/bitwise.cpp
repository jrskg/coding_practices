#include<iostream>
#include<math.h>
using namespace std;

void decToBin(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    string ans = "";
    while(n != 0){
        ans = to_string(n & 1) + ans;
        n = n>>1;
    }   
    cout<<ans<<endl; 
}

void binToDec(){
    int n, ans = 0;
    cout<<"Enter a number : ";
    cin>>n;
    for(int i = 0; n != 0; i++){
        if((n%10) & 1){
            ans += pow(2, i);
        }
        n = n/10;
    }
    cout<<ans<<endl;
}

int totalNumberOnes(int a, int b){
    int count = 0;
    while((a != 0) && (b != 0)){
        if(a & 1 == 1){
            count++;
        }
        if(b & 1 == 1){
             count++;
        }
        a = a >> 1;
        b = b >> 1;
    }
    return count;
}

bool powerOfTwo(int n){
    string bits = "";
    while (n != 0){
        if(n & 1 == 1){
            bits += to_string(n&1);
        }
        n = n >> 1;
    }
    return bits.size() == 1 ? true : false;
}

int main(){
    // int a, b;
    // cout<<"Enter two numbers : ";
    // cin>>a>>b;
    // decToBin()
    // binToDec();
    // cout<<"Total number of one's is : "<<totalNumberOnes(a, b)<<endl;


    int n;
    cout<<"Enter a number : ";
    cin>>n;

    if(powerOfTwo(n)){
        cout<<"Its a power of two"<<endl;
    }else{
        cout<<"Not a power of two"<<endl;
    }
   
    return 0;
}
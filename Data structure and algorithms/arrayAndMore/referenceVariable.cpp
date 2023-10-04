#include <iostream>
using namespace std;

void update(int &ref){
    ref++;
}

int main(){
    int n = 10;
    
    // int &m = n;
    // n++;
    // cout<<m<<endl;
    // cout<<n<<endl;
    // m++;
    // cout<<m<<endl;
    // cout<<n<<endl;

    // cout<<n<<endl;
    // update(n);
    // cout<<n<<endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void printVector(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

vector<int> seive(int num){
    vector<bool> prime(num+1, true);
    vector<int> res;
    for(int i = 2; i*i < num; i++){
        if(prime[i]){
            for(int j = 2*i; j <= num; j = j + i){
                prime[j] = false;
            }
        }
    }
    for(int i = 2; i <= num; i++){
        if(prime[i]){
            res.push_back(i);
        }
    }
    return res;
}

int main(){
    int lower, upper;
    cout<<"Enter lower bound : ";
    cin>>lower;
    cout<<"Enter upper bound : ";
    cin>>upper;
    vector<int> prime = seive(sqrt(upper));
    vector<bool> list(upper-lower+1, true);
    for(int i = 0; i < prime.size(); i++){
        int multiple = ceil((lower*1.0)/prime[i]);
        if(multiple == 1){
            multiple++;
        }
        int index = (multiple*prime[i])- lower;
        for(int j = index; j <= upper; j = j + prime[i]){
            list[j] = false;
        }
    }
    for(int i = 0; i < list.size(); i++){
        if(list[i]){
            cout<<i+lower<<" ";
        }
    }
    return 0;
}
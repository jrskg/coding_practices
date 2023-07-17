#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main(){
    //stl arrays********************************************
    // array<int, 5> arr = {10, 2, 3, 4, 5};
    // cout<<arr.at(2)<<endl;
    // cout<<arr.empty()<<endl;
    // cout<<arr.front()<<endl;
    // cout<<arr.back()<<endl;
    // cout<<arr.size()<<endl;
    // cout<<arr[1]<<endl;
    // for(auto i:arr){
    //     cout<<i<<" ";
    // }

    // stl vector ***********************************************
    vector<int> v;
    cout<<v.capacity()<<endl;
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(6);
    cout<<v.size()<<endl;
    cout<<v.at(1)<<endl;
    cout<<v.capacity()<<endl;
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    for(int i:v){
        cout<<i<<" ";
    }

    vector<int> okay(v);
    for(int i:okay){
        cout<<i<<" ";
    }

    return 0;
}
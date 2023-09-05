#include <iostream>
#include <vector>
using namespace std;

void print2DVector(vector<vector<int>> &arr){
    cout<<endl;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i].size() == 0){
            cout<<"empty";
        }
        for(int j = 0; j < arr[i].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> subset(int *arr, int size){
    vector<vector<int>> outer;
    outer.push_back({});

    for(int i = 0; i < size; i++){
        int n = outer.size();
        for(int j = 0; j < n; j++){
            vector<int> internal(outer[j]);
            internal.push_back(arr[i]);
            outer.push_back(internal);
        }
    }
    return outer;
}

int main() {
    int size;
    cout<<"Enter size : ";
    cin>>size;
    int *arr = new int[size];
    cout<<"Enter elements : ";
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    vector<vector<int>>ans = subset(arr, size);
    print2DVector(ans);

    delete []arr;
    return 0;
}
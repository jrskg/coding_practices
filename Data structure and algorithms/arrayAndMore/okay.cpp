#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>arr, int size){
    cout<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(vector<int>&arr, int size){
    for(int i = 0; i < size-1; i++){
        int min = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

void duplet(vector<int> arr, int target){
    int size = arr.size();
    selectionSort(arr, size);
    int i = 0, j = size-1;

    int elem1 = 0, elem2 = 0;

    while(j >= i){
        if(arr[i] + arr[j] == target){
            elem1 = arr[i];
            elem2 = arr[j];
            break;
        }else if(arr[i] + arr[j] < target){
            i++;
        }else{
            j--;
        }
    }
    cout<<"First is "<<elem1<<endl;
    cout<<"Second is "<<elem2<<endl;
}

int main() {
    vector<int>arr = {6, 5, 3, 4, 6, 1};
    int target = 12;
    duplet(arr, target);
    return 0;
}
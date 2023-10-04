#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void reverse(int arr[], int start, int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotate(int arr[], int size, int d){
    if(d == 0 || d == size) return;
    d = d%size;

    for (int i = 0; i < d; i++){
       int temp = arr[0];
       for(int j = 0; j < size-1; j++){
           arr[j] = arr[j+1];
       }
       arr[size-1] = temp;
    }
    
}

void cyclicallyRotate(int arr[], int n){
    int le = arr[n-1], i;
    for(i = n-2; i >= 0; i--){
        arr[i+1] = arr[i];
    }
    arr[i+1] = le;
}

void reverseRotate(int arr[], int size, int d){
    if(d == 0 || d == size) return;
    d = d%size;
    reverse(arr, 0, d-1);
    reverse(arr, d, size-1);
    reverse(arr, 0, size-1);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    // printArray(arr, 7);
    // rotate(arr, 7, 6);
    // printArray(arr, 7);

    // reverseRotate(arr, 7, 2);
    // printArray(arr, 7);

    cyclicallyRotate(arr, 7);
    printArray(arr, 7);
    return 0;
}
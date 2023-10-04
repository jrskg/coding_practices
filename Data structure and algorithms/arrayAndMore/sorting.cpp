#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    cout<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int arr[], int size){
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

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        bool isSorted = true;
        cout<<i<<"th round"<<endl;
        for(int j = 0; j < size-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSorted = false;
            }
        }
        if(isSorted){
            break;
        }
    }
}

void insertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i-1;
        while (j >= 0){
            if(key < arr[j]){
                arr[j+1] = arr[j];
                j--;
            }else{
                break;
            }
        }
        arr[j+1] = key;
    }
}

int main(){
    int size;
    int arr[100];
    cout<<"Enter the size of the array : ";
    cin>>size;
    cout<<"Now enter the elements"<<endl;

    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }

    insertionSort(arr, size);
    printArray(arr, size);

    return 0;
}
#include <iostream>
using namespace std;

void heapify(int *arr, int idx, int size){
  int largest = idx;
  int left = (2*idx) + 1;  
  int right = (2*idx) + 2;  

  if(left < size && arr[left] > arr[largest]){
    largest = left;
  }
  if(right < size && arr[right] > arr[largest]){
    largest = right;
  }

  if(largest != idx){
    swap(arr[largest], arr[idx]);
    heapify(arr, largest, size);
  }
}

void buildHeap(int *arr, int size){
  for(int i = (size/2)-1; i >= 0; i--){
    heapify(arr, i, size);
  }
}

void print(int *arr, int size){
  cout<<endl;
  for(int i = 0; i < size; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void heapSort(int *arr, int size){
  buildHeap(arr, size);
  while(size > 1){
    swap(arr[0], arr[size-1]);
    size--;
    heapify(arr, 0, size);
  }
}

int main() {
  int arr[] = {10, 20, 45, 67, 1, 2, 4, 90};
  // buildHeap(arr, 8);
  heapSort(arr, 8);
  print(arr, 8);
  return 0;
}
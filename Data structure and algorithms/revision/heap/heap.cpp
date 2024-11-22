#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
  int *arr;
  int capacity, size;
  public:
  MaxHeap(int size){
    arr = new int[size];
    this->size = 0;
    capacity = size;
  }
  void insert(int data){
    if(size == capacity){
      cout<<"Heap is full"<<endl;
      return;
    }
    arr[size] = data;
    int idx = size;
    size++;
    int parentIdx = (idx-1)/2;
    while(parentIdx >= 0 && arr[parentIdx] < arr[idx]){
      swap(arr[parentIdx], arr[idx]);
      idx = parentIdx;
      parentIdx = (idx-1)/2;
    }
  }

  void heapify(int index){
    int largest = index;
    int left = (index*2)+1;
    int right = (index*2)+2;

    if(left < size && arr[left] > arr[largest]) largest = left;
    if(right < size && arr[right] > arr[largest]) largest = right;

    if(largest != index){
      swap(arr[index], arr[largest]);
      heapify(largest);
    }
  }
  int remove(){
    if(size == 0) return -1;
    int ans = arr[0];
    arr[0] = arr[size-1];
    size--;
    heapify(0);
    // int idx = 0, leftIdx = (idx*2)+1, rightIdx = (idx*2)+2;
    // while(leftIdx < size){
    //   if(rightIdx < size){
    //     if(arr[leftIdx] < arr[idx] && arr[rightIdx] < arr[idx]) break;
    //     if(arr[leftIdx] > arr[rightIdx]){
    //       swap(arr[idx], arr[leftIdx]);
    //       idx = leftIdx;
    //     }else{
    //       swap(arr[idx], arr[rightIdx]);
    //       idx = rightIdx;
    //     }
    //   }else{
    //     if(arr[leftIdx] < arr[idx]) break;
    //     swap(arr[idx], arr[leftIdx]);
    //     idx = leftIdx;
    //   }
    //   leftIdx = (idx*2)+1;
    //   rightIdx = (idx*2)+2;
    // }
    return ans;
  }
  void printHeap(){
    cout<<endl;
    for(int i = 0; i < size; i++){
      cout<<arr[i]<<" ";
    }cout<<endl;
  }
};

int main() {
  MaxHeap h1(10);

  h1.insert(10);
  h1.insert(5);
  h1.insert(7);
  h1.insert(50);
  h1.insert(1);
  h1.insert(90);
  h1.insert(100);
  cout<<"Removed : "<<h1.remove()<<endl;
  cout<<"Removed : "<<h1.remove()<<endl;
  cout<<"Removed : "<<h1.remove()<<endl;
  cout<<"Removed : "<<h1.remove()<<endl;
  cout<<"Removed : "<<h1.remove()<<endl;
  cout<<"Removed : "<<h1.remove()<<endl;
  cout<<"Removed : "<<h1.remove()<<endl;

  h1.printHeap();
  return 0;
}
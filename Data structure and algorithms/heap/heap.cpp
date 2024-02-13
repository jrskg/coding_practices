#include <iostream>
#include <vector>
using namespace std;

// heap is a data-structure which is a complete binary tree which satisfy a order property
// complete binary tree is a binary tree in which every level, except the last, is completely filled and all node in the last level are as far left as possible

// Order property ->
/*
    1). Min heap -> all children of a node must be greater than or equal to the node.
    2). Max heap -> all children of a node must be less than or equal to the node.

    We will use array to implement heap

    index 0    1    2    3    4    5
    node -1    50   30   40   20   10

    we will store nothing in the 0th index ie -1
    for a given node (index) in 1 based indexing
        - its left child = 2*index
        - its right child = 2*index+1
        - its parent = index/2

    for a given node (index) in 0 based indexing
        - its left child = 2*index + 1
        - its right child = 2*index + 2
        - its parent = if index is odd then index/2 else (index/2)-1
*/

void printVector(vector<int> &arr){
  for(int i = 0; i < arr.size(); i++){
    cout<<arr[i]<<" ";
  }cout<<endl;
}

class Heap{
  private:
  int arr[100];
  int size;

  public:
  Heap(){
    size = 0;
  }

  void insert(int data){
    size = size + 1;
    int index = size;
    arr[index] = data;

    while(index > 1){
      int parent = index/2;
      if(arr[parent] < arr[index]){
        swap(arr[parent], arr[index]);
        index = parent;
      }else{
        return ;
      }
    }
  }

  void deleteFromHeap(){
    if(size == 0){
      return;
    }
    arr[1] = arr[size];
    size = size - 1;

    int i = 1;

    while(i < size){
      int leftIndex = i*2;
      int rightIndex = i*2+1;

      if(leftIndex <= size && arr[i] < arr[leftIndex]){
        swap(arr[i], arr[leftIndex]);
        i = leftIndex;
      }
      else if(rightIndex <= size && arr[i] < arr[rightIndex]){
        swap(arr[i], arr[rightIndex]);
        i = rightIndex;
      }
      else{
        return;
      }
    }
  }

  void printHeap() {
    for(int i = 1; i <= size; i++){
      cout<<arr[i] << " ";
    }
    cout<<endl;
  }
};


void heapifyMax(vector<int> &arr, int size, int i){
  int largest = i;
  int left = 2*i+1;
  int right = 2*i+2;

  //in 0 based indexing (left or right < size) but in 1 based (left or right <= size)
  if(left < size && arr[largest] < arr[left]){
    largest = left;
  }
  if(right < size && arr[largest] < arr[right]){
    largest = right;
  }

  if(largest != i){
    swap(arr[largest], arr[i]);
    heapifyMax(arr, size, largest);
  }
}
vector<int>buildMaxHeap(vector<int>arr){
  int size = arr.size();
  //in 0 based indexing leaf node starts from (size/2) and in 1 based (size/2)-1
  for(int i = (size/2)-1; i >= 0; i--){
    heapifyMax(arr, size, i);
  }
  return arr;
}

void heapifyMin(vector<int> &arr, int size, int i){
  int smallest = i;
  int left = i*2+1;
  int right = i*2+2;

  //in 0 based indexing (left or right < size) but in 1 based (left or right <= size)
  if(left < size && arr[smallest] > arr[left]){
    smallest = left;
  }
  if(right < size && arr[smallest] > arr[right]){
    smallest = right;
  }

  if(smallest != i){
    swap(arr[smallest], arr[i]);
    heapifyMin(arr, size, smallest);
  }
}
vector<int> buildMinHeap(vector<int> arr){   
  int size = arr.size();
  for(int i = (size/2)-1; i >= 0; i--){
    heapifyMin(arr, size, i);
  }
  return arr;
}

void heapSort(vector<int> &arr){
  int temp = arr.size()-1;
  while(temp > 0){
    swap(arr[0], arr[temp]);
    temp--;
    heapifyMax(arr, temp, 0);
  }
}

int main(){
  // Heap hp;
  // hp.insert(50);
  // hp.printHeap();
  // hp.insert(30);
  // hp.printHeap();
  // hp.insert(40);
  // hp.printHeap();
  // hp.insert(100);
  // hp.printHeap();
  // hp.insert(20);
  // hp.printHeap();
  // hp.deleteFromHeap();
  // hp.printHeap();

  vector<int> arr = {52, 2, 3, 4, 5};
  arr = buildMaxHeap(arr);
  printVector(arr);
  heapSort(arr);
  printVector(arr);

  return 0;
}
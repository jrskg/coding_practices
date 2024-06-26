#include <stdio.h>

void printArr(int* arr, int size){
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void bubbleSort(int* arr, int size){
  for(int i = 0; i < size-1; i++){
    for(int j = 0; j < size-1-i; j++){
      if(arr[j] > arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void selectionSort(int* arr, int size){
  for(int i = 0; i < size-1; i++){
    int min = i;
    for(int j = i+1; j < size; j++){
      if(arr[min] > arr[j])
        min = j;
    }
    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
  }
}

void insertionSort(int* arr, int size){
  for(int i = 1; i < size; i++){
    int elem = arr[i];
    int j = i-1;
    while(j >= 0 && arr[j] > elem){
      if(arr[j] > elem)
        arr[j+1] = arr[j];

      j--;
    }
    arr[j+1] = elem;
  }
}

int partition(int* arr, int s, int e){
  int pos = s;
  for(int i = s; i <= e; i++){
    if(arr[i] <= arr[e]){
      int temp = arr[pos];
      arr[pos] = arr[i];
      arr[i] = temp;
      pos++;
    }
  }
  return pos-1;
}

void quickSort(int* arr, int s, int e){
  if(s >= e) return;
  int pivot = partition(arr, s, e);
  quickSort(arr, s, pivot-1);
  quickSort(arr, pivot+1, e);
}

void merge(int* arr, int s, int m, int e){
  int size = e-s+1;
  int temp[size];
  int i = s, j = m+1, k = 0;
  while(i <= m && j <= e){
    if(arr[i] < arr[j])
      temp[k] = arr[i++];
    else 
      temp[k] = arr[j++];

    k++;
  }

  while(i <= m)
    temp[k++] = arr[i++];

  while(j <= e)
    temp[k++] = arr[j++];

  k = 0;
  while(s <= e)
    arr[s++] = temp[k++]; 
}

void mergeSort(int* arr, int s, int e){
  if(s == e) return;
  int m = s + (e-s)/2;
  mergeSort(arr, s, m);
  mergeSort(arr, m+1, e);
  merge(arr, s, m, e);
}

int main() {
  int size = 5;
  int arr[] = {6, 5, 3, 2, 1};
  // bubbleSort(arr, size);
  // selectionSort(arr, size);
  // insertionSort(arr, size);
  // quickSort(arr, 0, 4);
  mergeSort(arr, 0, 4);
  printArr(arr, size);
  return 0;
}
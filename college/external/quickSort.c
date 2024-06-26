#include <stdio.h>

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

int main() {
  int arr[] = {5, 4, 3, 2, 1};
  quickSort(arr, 0, 4);

  for(int i = 0; i < 5; i++){
    printf("%d ", arr[i]);
  }

  printf("\n");
  return 0;
}
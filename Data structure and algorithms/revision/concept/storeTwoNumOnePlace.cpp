#include <iostream>
#include <vector>
using namespace std;

vector<int> findTwoElement(vector<int> arr) {
  // here using n because i have decreased the element of array by 1 otherwise it should be n+1 everywhere
  //get original = val % n
  //get count = val / n
  //compress = val + n*count
  int r, m, n = arr.size();
  for(int i = 0; i < n; i++){
    arr[i]--;
  }
  
  for(int i = 0; i < n; i++){
    int idx = arr[i] % n;
    arr[idx] = arr[idx] + n;
  }
  
  for(int i = 0; i < n; i++){
    int count = arr[i] / n;
    if(count == 0)
      m = i + 1;
        
    if(count == 2)
      r = i + 1;
  }
  
  return {r, m};
}

void frequencyCount(vector<int>& arr,int N, int P){ 
  for(int i = 0; i < N; i++)
    arr[i]--;
  
  for(int i = 0; i < N; i++){
    int idx = arr[i] % P;
    if(idx >= N)
      arr[i] = 0 + (arr[i]/P) * P;
    else{
      arr[idx] = arr[idx] + P;
    }
  }
  
  for(int i = 0; i < N; i++)
    arr[i] = arr[i] / P;
}


int main() {
  
  return 0;
}
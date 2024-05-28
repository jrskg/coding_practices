#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void printVector(vector<int> &arr) {
  cout<<endl<<endl;
  int n = arr.size();
  if(n == 0){
    cout<<"Vector is empty"<<endl;
    return;
  }
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
} 

void segregate0and1(vector<int> &arr) {
  int i = 0, j = arr.size()-1;
  while(i <= j){
    if(arr[i] == 1 && arr[j] == 0)
      swap(arr[i++], arr[j--]);
        
    else if(arr[i] == 0)
      i++;
        
    else if(arr[j] == 1)
      j--;
  }
}

vector<int> twoSum(vector<int>& numbers, int target) {
  int n = numbers.size();
  int i = 0, j = n-1;
  while(i < j){
    int sum = numbers[i] + numbers[j];
    if(sum == target)
      break;
    else if(sum < target)
      i++;
    else
      j--;
  }

  //because 1-indexed array that's why adding 1 to both index
  return {i+1, j+1};
}

int twoDifference(vector<int> &nums, int target) {
  sort(nums.begin(), nums.end());
  int n = nums.size(), i = 0, j = 1;
  
  if(target < 0)
    target *= (-1);
      
  while(i < n &&j < n){
    int diff = nums[j] - nums[i];
    if(diff == target)
      return 1;
    else if(diff < target)
      j++;
    else
      i++;

    if(i == j)
      j++;
  }
  
  return 0;
}

bool equalSubArray(vector<int> &arr){
  int totalSum = 0, prefix = 0, n = arr.size();

  for(int i = 0; i < n; i++){
    totalSum += arr[i];
  }

  for(int i = 0; i < n - 1; i++){
    prefix += arr[i];
    if(totalSum - prefix == prefix)
      return true;
  }

  return false;
}


long long maxSubArraySum(vector<int> &arr){
  //will throw TLE because TC -> O(n^2)
  long long maxi = INT32_MIN, n = arr.size();
  for(int i = 0; i < n; i++){
    long long prefix = 0;
    for(int j = i; j < n; j++){
      prefix += arr[j];
      maxi = max(prefix, maxi);
    }
  }
  
  return maxi;
}

long long kadanesAlgo(vector<int> &arr){
  long long maxi = INT32_MIN, prefix = 0;
  int n = arr.size();
  for(int i = 0; i < n; i++){
    prefix += arr[i];
    maxi = max(maxi, prefix);
    if(prefix < 0)
      prefix = 0;
  }
  
  return maxi;
}

int maxDifference(vector<int> &arr){
  int n = arr.size();
  int ans = INT32_MIN, suffix = arr[n-1];

  for(int i = n - 2; i >= 0; i--){
    ans = max(ans, suffix - arr[i]);
    suffix = max(suffix, arr[i]);
  }

  return ans;
}

vector<int> maxPrefixes(int a[], int L[], int R[], int N, int Q) {
  //max prefixes from range L to R
  vector<int> ans;
  for(int i = 0; i < Q; i++){
    int prefix = 0, maxi = INT32_MIN;
    for(int j = L[i]; j <= R[i]; j++){
      prefix += a[j];
      maxi = max(prefix, maxi);
    }
    ans.push_back(maxi);
  }
  
  return ans;
}

vector<int> EqualSum(int a[], int n){
  int minAns = INT32_MAX, subArray = 1, position = 2, prefix = 0, totalSum = 0;
  
  for(int i = 0; i < n; i++){
    totalSum += a[i];
  }
  
  for(int i = 0; i < n; i++){
    prefix += a[i];
    int diff = totalSum - (2*prefix);
    int toCheck = diff < 0 ? (-1*diff) : diff;
    
    if(minAns > toCheck){
      if(diff < 0){
        minAns = (-1*diff);
        subArray =2;
      }else{
        minAns = diff;
        subArray = 1;
      }
      position = i + 2;
    }
  }
  
  return {minAns, position, subArray};
}

int trapRainWater(vector<int>& height) {
  int n = height.size(), maxHeight = INT32_MIN, idx;
  for(int i = 0; i < n; i++){
    if(maxHeight < height[i]){
      maxHeight = height[i];
      idx = i;
    }
  }

  int maxLeft = 0, maxRight = 0, ans = 0;
  for(int i = 0; i < idx; i++){
    if(maxLeft > height[i]){
      ans += (maxLeft - height[i]);
    }
    maxLeft = max(maxLeft, height[i]);
  }

  for(int i = n-1; i > idx; i--){
    if(maxRight > height[i]){
      ans += (maxRight - height[i]);
    }
    maxRight = max(maxRight, height[i]);
  }

  return ans;
}

bool threeSum(int A[], int n, int X){
  sort(A, A+n);
  for(int i = 0; i < n - 2; i++){
    int temp = X-A[i];
    int start = i+1, end = n - 1;
    while(start < end){
      if(A[start] + A[end] == temp)
        return true;
      else if(A[start] + A[end] > temp)
        end--;
      else
        start++;
    }
  }
  
  return false;
}

bool fourSum(int A[], int n, int X) {
  sort(A, A+n);
  for(int i = 0; i < n-3; i++){
    for(int j = i+1; j < n-2; j++){
      int temp = X-A[i]-A[j];
      int start = j+1, end = n-1;
      while(start < end){
        if(A[start] + A[end] == temp)
          return true;
        else if(A[start] + A[end] > temp)
          end--;
        else
          start++;
      }
    }
  }
  
  return false;
}

int removeElement(vector<int> &A, int B) {
  int n = A.size();
  int i = 0, j = n-1;
  while(i < j){
      if(A[i] == B && A[j] != B)
          swap(A[i++], A[j--]);
      else if(A[i] != B)
          i++;
      else if(A[j] == B)
          j--;
  }
  
  A.resize(i);
  return i;
}

int main() {
  // vector<int> v = {1, 0, 1, 0, 1, 0, 0};
  // segregate0and1(v);

  // vector<int> nums = {20, 500, 1000, 200};
  // cout<<twoDifference(nums, 0)<<endl;

  // vector<int> arr = {3, 4, -2, 5};
  // cout<<equalSubArray(arr)<<endl;
  // cout<<maxSubArraySum(arr)<<endl;
  // cout<<kadanesAlgo(arr)<<endl;
  // cout<<maxDifference(arr)<<endl;

  int size;
  cout<<"Enter size : ";
  cin>>size;
  vector<int> v(size);
  for(int i = 0; i < size; i++){
    cin>>v[i];
  }
  cout<<"The size is" <<removeElement(v, 0)<<endl<<endl;
  printVector(v);
  return 0;
}
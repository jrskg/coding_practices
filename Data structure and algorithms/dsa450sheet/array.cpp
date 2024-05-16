#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

void printVector(vector<int> &vec){
  cout<<endl;
  int size = vec.size();
  for(int i = 0; i < size; i++){
    cout<<vec[i]<<" ";
  }
  cout<<endl;
}

void reverseArray(vector<int> &vec){
  int i = 0, j = vec.size() - 1;
  while(i < j){
    swap(vec[i++], vec[j--]);
  }
}

int findSum(int A[], int N){
  int max = INT32_MIN, min = INT32_MAX;
  for(int i = 0; i < N; i++){
    if(A[i] < min)
      min = A[i];
        
    if(A[i] > max)
      max = A[i];
  }
  
  return max+min;
}

int kthSmallest(vector<int> &arr, int l, int r, int k) {
  priority_queue <int> q;
  for(int i = l; i < k; i++){
    q.push(arr[i]);
  }
  
  for(int i = k; i <= r; i++){
    q.push(arr[i]);
    q.pop();
  }
  return q.top();
}

void sort012(vector<int> &a){
  int zeros = 0, ones = 0, twos = 0;
  int n = a.size();
  for(int i = 0; i < n; i++){
    if(a[i] == 0)
      zeros++;
        
    if(a[i] == 1)
      ones++;
        
    if(a[i] == 2)
      twos++;
  }
  
  for(int i = 0; i < zeros; i++){
    a[i] = 0;
  }
  
  for(int i = zeros; i < zeros+ones; i++){
    a[i] = 1;
  }
    
  for(int i = zeros+ones; i < zeros+ones+twos; i++){
    a[i] = 2;
  }
}

void sort012Efficient(vector<int> &a){
  int low = 0, mid = 0, high = a.size()-1;
  while(mid <= high){
    if(a[mid] == 0){
      swap(a[low++], a[mid++]);
    }else if(a[mid] == 1){
      mid++;
    }else{
      swap(a[mid], a[high--]);
    }
  }
}

void moveNegative(vector<int> &nums){
  int i = 0, j = nums.size()-1;

  while(i < j){
    while(i <= j){
      if(nums[i] > 0 && nums[j] < 0){
        swap(nums[i++], nums[j--]);
      }
      else if(nums[i] <= 0){
        i++;
      }
      else{
        j--;
      }
    }
  }
}

int unionCount(vector<int> &nums1, vector<int> &nums2){
  unordered_map<int, bool> maps;
  
  int s1 = nums1.size();
  int s2 = nums2.size();
  
  for(int i = 0; i < s1; i++){
    maps[nums1[i]] = true;
  }
  
  for(int i = 0; i < s2; i++){
    maps[nums2[i]] = true;
  }
  
  return maps.size();
}

vector<int> intersection(vector<int> &nums1, vector<int> &nums2){
  unordered_map<int, bool> maps;
  vector<int> ans;
  
  int s1 = nums1.size();
  int s2 = nums2.size();
  
  for(int i = 0; i < s1; i++){
    maps[nums1[i]] = true;
  }
  
  for(int i = 0; i < s2; i++){
    if(maps[nums2[i]]){
      ans.push_back(nums2[i]);
      maps[nums2[i]] = false;
    }
  }
  return ans;
}

void rotateByOne(vector<int> &arr){
  int size = arr.size();
  int lastElement = arr[size-1];

  for(int i = size-1; i >= 0; i--){
    arr[i] = arr[i-1];
  }
  arr[0] = lastElement;
}

int maxSumK(vector<int> &arr, int k){
  int sum = 0;
  int size = arr.size();
  for(int i = 0; i < k; i++)
    sum += arr[i];

  int maxi = sum;
  int i = 0, j = k-1;

  while(j != size-1){
    sum = sum - arr[i] + arr[j+1];
    maxi = max(sum, maxi);
    i++, j++;
  }

  return maxi;
}

int maxSumContSubArray(vector<int> &arr){
  int maxi = INT32_MIN, temp;
  int size = arr.size();
  for(int i = 0; i < size; i++){
    temp = maxSumK(arr, i+1);
    maxi = max(maxi, temp);
  }

  return maxi;
}

long long maxSubarraySum(vector<int> &arr) {
  int n = arr.size();
  long long current_sum = 0;
  long long max_so_far = arr[0];

  for (int i = 0; i < n; i++) {
    current_sum = current_sum + arr[i];
    max_so_far = max(max_so_far, current_sum);
    if(current_sum < 0)
      current_sum = 0;
  }

  return max_so_far;
}

//not clear
int getMinDiff(int arr[], int n, int k) {
  sort(arr, arr+n);
  int ans = arr[n-1] - arr[0];
  int smallest = arr[0]+k;
  int largest = arr[n-1]-k;
  
  int mini = 0, maxi = 0;
  for(int i = 0; i < n-1; i++){
    mini = min(smallest, arr[i+1]-k);
    maxi = max(largest, arr[i]+k);
    
    if(mini < 0) continue;
    
    ans = min(ans, maxi-mini);
  }
  
  return ans;
}

//not clear
int minJumps(int arr[], int n){
  int maxR = arr[0];
  int steps = arr[0];
  int jump = 1;
  
  if(n == 1) return 0;
  else if(arr[0] == 0) return -1;
  else{
    for(int i = 1; i < n; i++){
      if(i >= n-1) return jump;
      maxR = max(maxR, i+arr[i]);
      steps--;
      if(steps == 0){
        jump++;
        if(i >= maxR) return -1;
        steps = maxR-i;
      }
    }
  }
}

int main() {
  // vector<int> vec = {1, 2, 3, 4, 5, 6};
  // reverseArray(vec);
  // printVector(vec);

  // vector<int> vec = {7, 10, 4, 3, 20, 15};
  // cout<<kthSmallest(vec, 0, 5, 3)<<endl;

  // vector<int> vec = {0, 2, 1, 2, 0, 1};
  // sort012(vec);
  // for(int i = 0; i < 5; i++){
  //   cout<<vec[i]<<"";
  // }cout<<endl;

  vector<int> vec = {1, 2, 3, -2, 5};
  // moveNegative(vec);
  // printVector(vec);

  // cout<<maxSumContSubArray(vec)<<endl;
  cout<<maxSubarraySum(vec)<<endl;


  return 0;
}

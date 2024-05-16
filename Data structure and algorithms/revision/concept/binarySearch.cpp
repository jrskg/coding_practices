#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
  int size = nums.size();
  int first = -1, last = -1;
  int start = 0, end = size - 1, mid;

  while(start <= end){
    mid = start + (end - start)/2;
    if(nums[mid] == target){
      first = mid;
      end = mid - 1;
    }else if(nums[mid] < target){
      start = mid + 1;
    }else{
      end = mid - 1;
    }
  }

  start = first == -1 ? 0 : first;
  end = size - 1;
  last = first;

  while(start <= end){
    mid = start + (end - start)/2;
    if(nums[mid] == target){
      last = mid;
      start = mid + 1;
    }else if(nums[mid] < target){
      start = mid + 1;
    }else{
      end = mid - 1;
    }
  }

  vector<int> ans = {first, last};
  return ans;
}

int searchInsert(vector<int>& nums, int target) {
  if(target < nums[0]){
    return 0;
  }
  int start = 0, end = nums.size()-1, mid;

  while(start <= end){
    mid = start + (end - start)/2;
    if(nums[mid] == target){
      return mid;
    }else if(target < nums[mid]){
      end = mid - 1;
    }else{
      start = mid + 1;
    }
  }
  return start;
}

int mySqrt(int x){
  if(x == 0) return 0;
  int ans, start = 1, end = x, mid;
  while(start <= end){
    mid = start + (end - start)/2;
    if(mid == x/mid)
      return mid;
    else if(mid > x/mid)
      end = mid - 1;
    else{
      ans = mid;
      start = mid + 1;
    }
  }
  return ans;
}

int countZeroes(int arr[], int n) {
  if(arr[0] == 0) return n;
  int last = -1;
  int start = 0, end = n-1, mid;
  
  while(start <= end){
    mid = start + (end - start) / 2;
    if(arr[mid] == 1){
      last = mid;
      start = mid + 1;
    }
    else if(arr[mid] < 1)
    //because all the 1s start first and then 0s
      end = mid - 1;
    else
      start = mid + 1;
  }
  
  return n-1-last;
}

int count(int arr[], int n, int x) {
  int first = -1, last = -1;
  int start = 0, end = n - 1, mid;
  
  while(start <= end){
    mid = start + (end - start)/2;
    if(arr[mid] == x){
      first = mid;
      end = mid - 1;
    }else if(arr[mid] < x)
      start = mid + 1;
    else
      end = mid - 1;
  }
  
  start = first == -1 ? 0 : first;
  last = first;
  end = n-1;
  
  while(start <= end){
    mid = start + (end - start)/2;
    if(arr[mid] == x){
      last = mid;
      start = mid + 1;
    }else if(arr[mid] < x)
      start = mid + 1;
    else
      end = mid - 1;
  }
  
  if(first == -1 && last == -1) return 0;
  return last-first+1;
}

int findKthPositive(vector<int>& arr, int k) {
  int ans, size = arr.size();
  int diff = arr[0] - 1;
  if(k < arr[0])
    return k;
  else
    k = k - diff;

  for(int i = 1; i < size; i++){
    int temp = arr[i] - arr[i-1]-1;
    if(temp > 0){
      if(temp >= k)
        return arr[i-1] + k;
      else
        k = k - temp;
    }
  }

  if(k != 0)
    ans = arr[size-1] + k;

  return ans;
}

int peakIndexInMountainArray(vector<int>& arr) {
  int start = 0;
  int end = arr.size()-1, mid;
  while(start <= end){
    //when you do start+(end-start)/2 then it will throw error because in some cases mid becomes 0 and (mid-1) will throw segmentation fault
    mid = end + (start - end)/2;
    if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
      return mid;
    }else if(arr[mid] > arr[mid-1]){
      start = mid + 1;
    }else{
      end = mid - 1;
    }
  }
  return -1;
}

int findMinRotated(vector<int>& nums) {
  int size = nums.size();
  if(size == 1)
    return nums[0];

  int start = 0, end = size - 1, mid, ans = nums[0];
  while(start <= end){
    mid = end + (start - end)/2;
    if(nums[mid] >= nums[0]){
      start = mid + 1;
    }else{
      ans = nums[mid];
      end = mid - 1;
    }
  }

  return ans;
}

int searchRotatedArray(vector<int>& nums, int target) {
  int size = nums.size();
  int start = 0, end = size - 1, ans = -1, mid;

  while(start <= end){
    mid = start + (end - start)/2;
    if(nums[mid] == target){
      ans = mid;
      break;
    }else if(nums[mid] >= nums[0]){
      if(target >= nums[start] && target <= nums[mid]){
        end = mid - 1;
      }else{
        start = mid + 1;
      }
    }else{
      if(target >= nums[mid] && target <= nums[end]){
        start = mid + 1;
      }else{
        end = end - 1;
      }
    }
  }

  return ans;
}

int main() {
  cout<<mySqrt(1)<<endl;
  return 0;
}
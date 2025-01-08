#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countZeroSubArraySum(vector<int> &arr){
  unordered_map<int, int>map;
  map[0] = 1;
  int curr = 0, count = 0;
  for(int i = 0; i < arr.size(); i++){
    curr += arr[i];
    if(map[curr]){
      count += map[curr];
      map[curr]++;
    }else map[curr] = 1;
  }
  return count;
}

int countSubArraySumEqualK(vector<int> &arr, int k){
  unordered_map<int, int> map;
  map[0] = 1;
  int total = 0, curr = 0;
  for(int i = 0; i < arr.size(); i++){
    curr += arr[i];
    if(map[curr-k]){
      total += map[curr-k];
    }
    if(map[curr]) map[curr]++;
    else map[curr] = 1;
  }

  return total;
}

int countSubArraySumDivisibleByK(vector<int> &arr, int k){
  unordered_map<int, int> map;
  map[0] = 1;
  int curr = 0, total = 0, rem;
  for(int i = 0; i < arr.size(); i++){
    curr += arr[i];
    rem = curr%k < 0 ? curr%k+k : curr%k;
    if(map[rem]){
      total += map[rem];
      map[rem]++;
    }else map[rem] = 1;
  }

  return total;
}

int numSubarrayProductLessThanK(vector<int> &arr, int k){
  int start = 0, end = 0, count = 0;
  int prod = 1;

  while(end < arr.size()){
    prod *= arr[end];
    while(prod >= k){
      prod /= arr[start];
      start++;
    }
    count += (end-start+1);
    end++;
  }
  return count;
}

long long countSubarrays(vector<int>& nums, long long k) {
  int start = 0, end = 0;
  long long curr = 0, count = 0;

  while(end < nums.size()){
    curr += nums[end];
    int wsize = end-start+1;
    while((curr*wsize) >= k && start <= end){
      curr -= nums[start];
      start++;
      wsize = end-start+1;
    }
    count += wsize;
    end++;
  }
  return count;
}

int minSubArrayLen(vector<int> &nums, int target){
  int s = 0,  e = 0;
  int curr = 0, ans = nums.size();
  bool hasAny = false;

  while(e < nums.size()){
    curr += nums[e];
    while(curr >= target && s <= e){
      int currSize = e-s+1;
      hasAny = true;
      ans = min(ans, currSize);
      curr -= nums[s];
      s++;
    }
    e++;
  }
  return hasAny ? ans : 0;
}

string minWindow(string s, string t) {
  int start = 0, end = 0, ansStart = 0, ansEnd = 0, ans = __INT16_MAX__;
  int reqCount = t.size();
  unordered_map<char, int>map;
  for(int i = 0; i < reqCount; i++){
    map[t[i]]++;
  }

  while(end < s.size()){
    map[s[end]]--;
    if(map[s[end]] >= 0) reqCount--;
    while(reqCount == 0 && start <= end){
      if(ans > (end-start+1)){
        ans = end-start+1;
        ansStart = start;
        ansEnd = end;
      }
      map[s[start]]++;
      if(map[s[start]] > 0)reqCount++;
      start++;
    }
    end++;
  }
  if(ans == __INT16_MAX__) return "";
  string ansStr = "";
  for(int i = ansStart; i <= ansEnd; i++){
    ansStr.push_back(s[i]);
  }

  return ansStr;
}

int maxSubarrayLength(vector<int>& nums, int k) {
  int start = 0, end = 0, ans = 0;
  unordered_map<int, int> map;
  while(end < nums.size()){
    map[nums[end]]++;
    while(map[nums[end]] > k && start <= end){
      map[nums[start]]--;
      start++;
    }
    ans = max(ans, end-start+1);
    end++;
  }

  return ans;
}

long long countSubarrays(vector<int>& nums, int k) {
  int maxi = nums[0], maxiCount = 0, n = nums.size();
  int start = 0, end = 0;
  long long ans = 0;

  for(int i = 1; i < n; i++){
    maxi = max(maxi, nums[i]);
  }

  while(end < n){
    if(nums[end] == maxi) maxiCount++;
    while(maxiCount >= k && start <= end){
      ans += n-end;
      if(nums[start] == maxi) maxiCount--;
      start++;
    }
    end++;
  }

  return ans;
}

//********************************************************** */
int atLeast(vector<int> &nums, int k){
  int start = 0, end = 0, count = 0, n = nums.size(), ans = 0;
  unordered_map<int, int> freq;

  while(end < n){
    freq[nums[end]]++;
    if(freq[nums[end]] == 1) count++;
    while(count >= k && start <= end){
      ans += n-end;
      freq[nums[start]]--;
      if(freq[nums[start]] == 0) count--;
      start++;
    }
    end++;
  }
  return ans;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
  return atLeast(nums, k) - atLeast(nums, k+1);
}
//********************************************************** */


int main() {
  vector<int> arr = {0, 0, 5, 5, 0, 0};
  cout<<countZeroSubArraySum(arr)<<endl;

  return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
  //moore voting algorithm
  int n = nums.size(), candidate = nums[0], count = 1;

  for(int i = 1; i < n; i++){
    if(nums[i] != candidate){
      if(count > 0)
        count--;
      else{
        candidate = nums[i];
        count = 1;
      }
    }else{
      count++;
    }   
  }
  //this is when it guaranteed that there will be an ans, in case if it is not guaranteed then verify the candidate by counting again if its is > n/2 then return it else -1, below is the code
  // count = 0;
  // for(int i = 0; i < n; i++){
  //   if(nums[i] == candidate)
  //     count++;
  // }
  // return count > (n/2) ? candidate : -1;

  return candidate;
}

int main() {
  
  return 0;
}
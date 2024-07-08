#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void subSequenceSolve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int i){
  if(i == nums.size()){
    ans.push_back(temp);
    return;
  }

  subSequenceSolve(nums, ans, temp, i+1);
  temp.push_back(nums[i]);
  subSequenceSolve(nums, ans, temp, i+1);
  temp.pop_back();
}

vector<vector<int>> subSequence(vector<int> &nums){
  vector<vector<int>> ans;
  vector<int> temp;
  subSequenceSolve(nums, ans, temp, 0);
  return ans;
}

void subSeqSumSolve(vector<int> &nums, vector<int> &ans, int i, int sum){
  if(i == nums.size()){
    ans.push_back(sum);
    return;
  }
  subSeqSumSolve(nums, ans, i+1, sum);
  sum += nums[i];
  subSeqSumSolve(nums, ans, i+1, sum);
}

vector<int> subSeqSum(vector<int> &nums){
  vector<int> ans;
  subSeqSumSolve(nums, ans, 0, 0);
  return ans;
}

void subSequenceStrSolve(string &str, vector<string> &ans, string &temp, int i){
  if(i == str.size()){
    ans.push_back(temp);
    return;
  }

  subSequenceStrSolve(str, ans, temp, i+1);
  temp.push_back(str[i]);
  subSequenceStrSolve(str, ans, temp, i+1);
  temp.pop_back();
}

vector<string> subSequenceStr(string &str){
  vector<string> ans;
  string temp;
  subSequenceStrSolve(str, ans, temp, 0);
  return ans;
}

void generateParenthesisSolve(int n, vector<string> &ans, int l, int r, string &temp){
  if(l == n && r == n){
    ans.push_back(temp);
    return;
  }

  if(l < n){
    temp.push_back('(');
    generateParenthesisSolve(n, ans, l+1, r, temp);
    temp.pop_back();
  }
  if(r < l && r < n){
    temp.push_back(')');
    generateParenthesisSolve(n, ans, l, r+1, temp);
    temp.pop_back();
  }
}
vector<string> generateParenthesis(int n) {
  vector<string> ans;
  string temp = "";
  generateParenthesisSolve(n, ans, 0, 0, temp);
  return ans;
}

void sumSubsetSolve(vector<int> &nums, vector<pair<int, vector<int>>> &ans, vector<int> &temp, int sum, int i){
  if(i == nums.size()){
    ans.push_back({sum, temp});
    return;
  }

  sumSubsetSolve(nums, ans, temp, sum, i+1);
  temp.push_back(nums[i]);
  sumSubsetSolve(nums, ans, temp, sum+nums[i], i+1);
  temp.pop_back();
}

vector<pair<int, vector<int>>>sumSubset(vector<int> &nums){
  vector<pair<int, vector<int>>> ans;
  vector<int> temp;
  sumSubsetSolve(nums, ans, temp, 0, 0);
  return ans;
}

void permuteArrSolve(vector<int> &arr, vector<vector<int>> &ans, vector<bool> &vis, vector<int> &temp){
  if(arr.size() == temp.size()){
    ans.push_back(temp);
    return;
  }

  for(int i = 0; i < arr.size(); i++){
    if(!vis[i]){
      vis[i] = true;
      temp.push_back(arr[i]);
      permuteArrSolve(arr, ans, vis, temp);
      vis[i] = false;
      temp.pop_back();
    }
  }
}

void permuteArrSolve2(vector<int> &arr, vector<vector<int>> &ans, int idx){
  if(idx == arr.size()){
    ans.push_back(arr);
    return;
  }

  for(int i = idx; i < arr.size(); i++){
    swap(arr[idx], arr[i]);
    permuteArrSolve2(arr, ans, idx+1);
    swap(arr[idx], arr[i]);
  }
}

void permuteArrSolve2Repeated(vector<int> &arr, vector<vector<int>> &ans, int idx){
  if(idx == arr.size()){
    ans.push_back(arr);
    return;
  }

  vector<bool> vis(21, false);// you can also use unordered_map

  for(int i = idx; i < arr.size(); i++){
    if(vis[arr[i] + 10] == 0){
      swap(arr[idx], arr[i]);
      permuteArrSolve2Repeated(arr, ans, idx+1);
      swap(arr[idx], arr[i]);
      vis[arr[i] + 10] = true;
    }
  }
}

vector<vector<int>> permuteArr(vector<int> &arr){
  vector<vector<int>> ans;
  vector<int> temp;
  vector<bool> vis(arr.size(), false);
  permuteArrSolve(arr, ans, vis, temp);
  // permuteArrSolve2(arr, ans, 0);
  // permuteArrSolve2Repeated(arr, ans, 0);
  return ans;
}

void permuteStrSolve(string &str, vector<string> &ans, int idx){
  if(idx == str.size()){
    ans.push_back(str);
    return;
  }
  unordered_map<char, bool> vis;

  for(int i = idx; i < str.size(); i++){
    if(!vis[str[i]]){
      swap(str[i], str[idx]);
      permuteStrSolve(str, ans, idx+1);
      swap(str[idx], str[i]);
      vis[str[i]] = true;
    }
  }
}

vector<string> permuteStr(string &str){
  vector<string> ans;
  permuteStrSolve(str, ans, 0);
  return ans;
}

int totalWays(vector<int> &nums, int sum){
  if(sum == 0)
    return 1;

  if(sum < 0)
    return 0;

  int ans = 0;
  for(int i = 0; i < nums.size(); i++)
    ans += totalWays(nums, sum - nums[i]);

  return ans % 1000000007;
}

int winnerIterative(int n, int k){
  // if(n == 1) return 1;
  if(k == 1) return n; // why to iterate

  vector<bool> arr(n, false);

  int i = 0, rem = n, kill;
  while(rem != 1){
    int kill = (k-1)%rem;
    while(kill--){
      i = (i+1)%n;
      while(arr[i] == true)
        i = (i+1)%n;
    }

    arr[i] = true;
    while(arr[i] == true)
      i = (i+1)%n;

    rem--;
  }

  int ans;
  for(i = 0; i < n; i++){
    if(arr[i] == false){
      ans = i+1;
      break;
    }
  }

  return ans;
}

int winnerRecursive(vector<bool> &person, int i, int rem, int k, int n){
  if(rem == 1){
    for(int z = 0; z < n; z++){
      if(person[z] == false)
        return z+1;
    }
  }

  int kill = (k-1)%rem;
  while(kill--){
    i = (i+1)%n;
    while(person[i] == true)
      i = (i+1)%n;
  }

  person[i] = true;
  while(person[i] == true)
    i = (i+1)%n;

  return winnerRecursive(person, i, rem-1, k, n);
}

int winnerRecOptimized(int n, int k){
  if(n == 1) return 0;
  return (winnerRecOptimized(n-1, k)+k) % n;
}

int winner(int n, int k){
  // return winnerIterative(n, k);
  // vector<bool> person(n, false);
  // return winnerRecursive(person, 0, n, k, n);

  return winnerRecOptimized(n, k) + 1;
}

void solveNBit(int n, vector<string> &ans, string &temp, int zero, int one){
  if(temp.size() == n){
    ans.push_back(temp);
    return;
  }
  temp.push_back('1');
  solveNBit(n, ans, temp, zero, one+1);
  temp.pop_back();

  if(zero < one){
    temp.push_back('0');
    solveNBit(n, ans, temp, zero+1, one);
    temp.pop_back();
  }
}

vector<string> nBitBinaryNumbers(int n){
  vector<string> ans;
  string temp = "";
  solveNBit(n, ans, temp, 0, 0);
  return ans;
}

void solveMoreOne(int n, vector<string> &ans, string &temp, int zero, int one){
  if(temp.size() == n){
    ans.push_back(temp);
    return;
  }
  temp.push_back('1');
  solveMoreOne(n, ans, temp, zero, one+1);
  temp.pop_back();

  if(zero+1 < one){
    temp.push_back('0');
    solveMoreOne(n, ans, temp, zero+1, one);
    temp.pop_back();
  }
}

vector<string> moreOneThanZero(int n){
  vector<string> ans;
  string temp = "";
  solveNBit(n, ans, temp, 0, 0);
  return ans;
}

int main() {
  // string str = "abc";
  // vector<string> ans = subSequenceStr(str);

  // vector<string> ans = generateParenthesis(3);
  // for(int i = 0; i < ans.size(); i++){
  //   cout<<ans[i]<<endl;
  // }

  // vector<int> nums = {1, 2, 3};
  // vector<pair<int, vector<int>>> ans = sumSubset(nums);
  // for(int i = 0; i < ans.size(); i++){
  //   cout<<ans[i].first<<" -> ";
  //   for(int j = 0; j < ans[i].second.size(); j++){
  //     cout<<ans[i].second[j]<<" ";
  //   }cout<<endl;
  // }

  // vector<int> arr = {1, 1, 2, 2};
  // vector<vector<int>> ans = permuteArr(arr);

  // for(int  i = 0; i < ans.size(); i++){
  //   for(int j = 0; j < ans[i].size(); j++){
  //     cout<<ans[i][j]<<" ";
  //   }cout<<endl;
  // }

  
  // string str = "abb";
  // vector<string> ans = permuteStr(str);
  // for(int i = 0; i < ans.size(); i++){
  //   cout<<ans[i]<<endl;
  // }

  // cout<<winner(3, 2)<<endl;
  // cout<<winner(7, 2)<<endl;
  // cout<<winner(1, 2)<<endl;
  // cout<<winner(3, 1)<<endl;

  // vector<string> ans = nBitBinaryNumbers(3);
  vector<string> ans = moreOneThanZero(5);
  for(int i = 0; i < ans.size(); i++){
    cout<<ans[i]<<endl;
  }

  return 0;
}
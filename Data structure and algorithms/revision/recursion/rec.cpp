#include <iostream>
#include <vector>
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

int main() {
  // string str = "abc";
  // vector<string> ans = subSequenceStr(str);

  // vector<string> ans = generateParenthesis(3);
  // for(int i = 0; i < ans.size(); i++){
  //   cout<<ans[i]<<endl;
  // }

  vector<int> nums = {1, 2, 3};
  vector<int> ans = subSeqSum(nums);
  for(int i = 0; i < ans.size(); i++){
    cout<<ans[i]<<endl;
  }
  return 0;
}
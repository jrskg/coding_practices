#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void insertAtBottom(stack<int> &st, int x){
  if(st.empty()){
    st.push(x);
    return;
  }
  int top = st.top();
  st.pop();
  insertAtBottom(st, x);
  st.push(top);
}

vector<int> beautiFyArray(vector<int> &arr){
  stack<int> st;
  for(int i = 0; i > arr.size(); i++){
    if(st.empty()) st.push(arr[i]);
    else if((st.top() >= 0 && arr[i] >= 0) || (st.top() < 0 && arr[i] < 0)) st.push(arr[i]);
    else st.pop();
  }

  vector<int> ans(st.size());
  int i = st.size() - 1;
  while(!st.empty()){
    ans[i--] = st.top();
    st.pop();
  }
  return ans;
}

int removeConsecutiveSame(vector<string> v) {
  stack<string> st;
  for(int i = 0; i < v.size(); i++){
    if(st.empty() || st.top() != v[i]) st.push(v[i]);
    else st.pop();
  }
  return st.size();
} 

int minAddtoMakeValid(string &s){
  stack<char> st;
  for(int i = 0; i < s.size(); i++){
    if(st.empty() || s[i] == '(') st.push(s[i]);
    else{
      if(st.top() == '(' && s[i] == ')') st.pop();
      else st.push(s[i]);
    }
  }
  return st.size();
}

int minAddtoMakeValid2(string &s){
  int op = 0, cl = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] =='(') op++;
    else{
      if(op > 0) op--;
      else cl++;
    }
  }
  return op + cl;
}

bool backspaceCompare(string s, string t) {
  stack<char> s1, s2;
  for(int i = 0; i < s.size(); i++){
    if(!s1.empty() && s[i] == '#') s1.pop();
    else if(s[i] != '#') s1.push(s[i]);
  }

  for(int i = 0; i < t.size(); i++){
    if(!s2.empty() && t[i] == '#') s2.pop();
    else if(t[i] != '#') s2.push(t[i]);
  }

  if(s1.size() != s2.size()) return false;
  while(!s1.empty()){
    if(s1.top() != s2.top()) return false;
    s1.pop();
    s2.pop();
  }
  return true;
}

vector<int> bracketNumbers(string &s){
  vector<int> ans;
  stack<int> st;
  int c = 0;

  for(int  i = 0; i < s.size(); i++){
    if(s[i] =='('){
      c++;
      ans.push_back(c);
      st.push(c);
    }else if(s[i] == ')'){
      ans.push_back(st.top());
      st.pop();
    }
  }
  return ans;
}

vector<int> nextGreaterElementRight(vector<int> &arr){
  int n = arr.size();
  vector<int> ans(n, -1);
  stack<int> st;

  for(int i = 0; i < n; i++){
    while(!st.empty() && arr[st.top()] < arr[i]){
      ans[st.top()] = arr[i];
      st.pop();
    }
    st.push(i);
  }
  return ans;
}

vector<int> nextGreaterElementLeft(vector<int> &arr){
  int n = arr.size();
  stack<int> st;
  vector<int> ans(n, -1);

  for(int i = n-1; i >= 0; i--){
    while(!st.empty() && arr[st.top()] < arr[i]){
      ans[st.top()] = arr[i];
      st.pop();
    }
    st.push(i);
  }
  return ans;
}

vector<int> nextSmallerElementRight(vector<int> &arr){
  int n = arr.size();
  vector<int> ans(n, -1);
  stack<int> st;

  for(int i = 0; i < n; i++){
    while(!st.empty() && arr[st.top()] > arr[i]){
      ans[st.top()] = arr[i];
      st.pop();
    }
    st.push(i);
  }
  return ans;
}

vector<int> nextSmallerElementLeft(vector<int> &arr){
  int n = arr.size();
  vector<int> ans(n, -1);
  stack<int> st;

  for(int i = n - 1; i >= 0; i--){
    while(!st.empty() && arr[st.top()] > arr[i]){
      ans[st.top()] = arr[i];
      st.pop();
    }
    st.push(i);
  }
  return ans;
}

vector<int> nextGreaterInCircularRight(vector<int> &arr){
  int n = arr.size();
  vector<int> ans(n, -1);
  stack<int> st;

  //iterating twice
  for(int i = 0; i < 2*n; i++){
    while(!st.empty() && arr[st.top()] < arr[i%n]){
      ans[st.top()] = arr[i%n];
      st.pop();
    }
    st.push(i%n);
  }
  return ans;
}

vector<int> stockSpan(vector<int> &price){
  int n = price.size();
  vector<int> ans(n, 1);
  stack<int> st;
  for(int i = n-1; i >= 0; i--){
    while(!st.empty() && price[st.top()] < price[i]){
      ans[st.top()] = st.top() - i;
      st.pop(); 
    }
    st.push(i);
  }

  while(!st.empty()){
    ans[st.top()] = st.top() + 1;
    st.pop();
  }
  return ans;
}

int maxRectangle(vector<int> &heights){
  int n = heights.size();
  vector<int> left(n, -1);
  vector<int> right(n, n);
  stack<int> st;

  //left smaller index
  for(int i = n-1; i >= 0; i--){
    while(!st.empty() && heights[st.top()] > heights[i]){
      left[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }

  while(!st.empty()) st.pop();

  //right smaller
  for(int i = 0; i < n; i++){
    while(!st.empty() && heights[st.top()] > heights[i]){
      right[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }

  int maxi = -1, curr;
  for(int i = 0; i < n; i++){
    curr = (right[i] - left[i] - 1) * heights[i];
    maxi = max(maxi, curr);
  }
  return maxi;
}

int maxRectangle2(vector<int> &heights){
  //in one pass (not applicable when max area of each rectangle is needed)
  stack<int> st;
  int n = heights.size(), maxi = -1, curr;

  for(int i = 0; i < n; i++){
    while(!st.empty() && heights[st.top()] > heights[i]){
      int rec = st.top();
      st.pop();
      if(st.empty()){
        curr = heights[rec] * i;
      }else{
        curr = heights[rec] * (i - st.top() - 1);
      }
      maxi = max(maxi, curr);
    }
    st.push(i);
  }

  while(!st.empty()){
    int rec = st.top();
    st.pop();
    if(st.empty()){
      curr = heights[rec] * n;
    }else{
      curr = heights[rec] * (n - st.top() - 1);
    }
    maxi = max(maxi, curr);
  }
  return maxi;
}

int maxRectangleCreatedBy1(vector<vector<char>> &mat){
  int row = mat.size(), col = mat[0].size();
  int maxi = -1;
  vector<int> heights(col, 0);

  for(int i =0 ; i < row; i++){
    for(int j = 0; j < col; j++){
      if(mat[i][j] == '1') heights[j]++;
      else heights[j] = 0;
    }
    maxi = max(maxi, maxRectangle2(heights));
  }
  return maxi;
}

int celebrity(vector<vector<int>> &mat){
  int n = mat.size();
  if(n == 1) return 0;
  stack<int> st;
  for(int i = 0; i < n; i++)
    st.push(i);

  int f, s;
  while(st.size() > 1){
    f = st.top(); st.pop();
    s = st.top(); st.pop();

    if(mat[f][s] && !mat[s][f])
      st.push(s);
    else if(!mat[f][s] && mat[s][f])
      st.push(f);
  }

  if(st.empty()) return -1;

  int row = 0, col = 0, top = st.top();
  for(int i = 0; i < n; i++){
    row += mat[top][i];
    col += mat[i][top];
  }
  return (row == 0 && col == n - 1) ? top : -1;
}

vector<int> maxOfMinInEveryWindow(vector<int> &arr){
  //Next smallest right and next smallest left concept
  int n = arr.size();
  vector<int> range(n), ans(n, 0);
  stack<int> st;

  for(int i = 0; i < n; i++){
    while(!st.empty() && arr[st.top()] > arr[i]){
      int top = st.top();
      st.pop();
      if(st.empty()) range[top] = i;
      else range[top] = i - st.top() - 1;
    }
    st.push(i);
  }

  while(!st.empty()){
    int top = st.top();
    st.pop();
    if(st.empty()) range[top] = n;
    else range[top] = n - st.top() - 1;
  }

  for(int i = 0; i < n; i++){
    ans[range[i] - 1] = max(ans[range[i]-1], arr[i]);
  }

  for(int i = n-2; i >= 0; i--){
    ans[i] = max(ans[i], ans[i+1]);
  }
  return ans;
}

vector<int> maxOfMinInEveryWindow2(vector<int> &arr){
  //same approach just little optimization
  int n = arr.size(), top, range;
  vector<int> ans(n, 0);
  stack<int> st;

  for(int i = 0; i < n; i++){
    while(!st.empty() && arr[st.top()] > arr[i]){
      top = st.top();
      st.pop();
      if(st.empty()) range = i;
      else range = i - st.top() - 1;
      ans[range-1] = max(ans[range-1], arr[top]);
    }
    st.push(i);
  }

  while(!st.empty()){
    top = st.top();
    st.pop();
    if(st.empty()) range = n;
    else range = n - st.top() - 1;
    ans[range-1] = max(ans[range-1], arr[top]);
  }

  for(int i = n-2; i >= 0; i--){
    ans[i] = max(ans[i], ans[i+1]);
  }
  return ans;
}

vector<int> minOfMaxInEveryWindow(vector<int> &arr){
  //Next greatest right and next greatest left concept
  int n = arr.size(), top, range;
  vector<int> ans(n, INT32_MAX);
  stack<int> st;

  for(int i = 0; i < n; i++){
    while(!st.empty() && arr[st.top()] < arr[i]){
      top = st.top();
      st.pop();
      if(st.empty()) range = i;
      else range = i - st.top() - 1;
      ans[range-1] = min(ans[range-1], arr[top]);
    }
    st.push(i);
  }
  while(!st.empty()){
    top = st.top();
    st.pop();
    if(st.empty()) range = n;
    else range = n - st.top() - 1;
    ans[range-1] = min(ans[range-1], arr[top]);
  }

  for(int i = n-2; i >= 0; i--){
    ans[i] = min(ans[i], ans[i+1]);
  }
  return ans;
}


int main() {
  vector<int> arr = {44, 22, 55, 1, 99, 91, 18};
  // vector<int> ans = nextSmallerElementLeft(arr);
  // vector<int> ans = nextGreaterElementLeft(arr);
  // vector<int> ans = stockSpan(arr);
  // vector<int> ans = maxOfMinInEveryWindow(arr);
  // vector<int> ans = maxOfMinInEveryWindow2(arr);
  vector<int> ans = minOfMaxInEveryWindow(arr);
  for(int i = 0; i < ans.size(); i++){
    cout<<ans[i]<<" ";
  }cout<<endl;

  // vector<int> heights = {4, 8, 6, 7, 5, 2, 9 };
  // cout<<maxRectangle(heights)<<endl;
  // cout<<maxRectangle2(heights)<<endl;
  return 0;
}
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
using namespace std;
queue<int> reverese(queue<int> q){
  stack<int> st;
  while(!q.empty()){
    st.push(q.front());
    q.pop();
  }
  
  while(!st.empty()){
    q.push(st.top());
    st.pop();
  }
  return q;
}

queue<int> reverseFirstKElement(queue<int> q, int k) {
  stack<int> st;
  int size = q.size();
  int count = k;
  
  while(count--){
    st.push(q.front());
    q.pop();
  }
  
  while(!st.empty()){
    q.push(st.top());
    st.pop();
  }
  
  for(int i = 0; i < (size-k); i++){
    int front = q.front();
    q.pop();
    q.push(front);
  }
  return q;
}

int timeRequiredToBuy(vector<int>& tickets, int k) {
  queue<int> q;
  int size = tickets.size();
  for(int  i = 0; i < size; i++)
  q.push(i);

  int timer = 0;

  while(tickets[k] != 0){
    int idx = q.front(); q.pop();
    tickets[idx]--;
    timer++;
    if(tickets[idx] == 0){
      if(idx == k) break;
    }
    else q.push(idx);
  }
  return timer;
}

int timeRequiredToBuy2(vector<int>& tickets, int k) {
  int timer = 0;
  for(int i = 0; i <= k; i++){
      timer += min(tickets[i], tickets[k]);
  }

  for(int i = k+1; i < tickets.size(); i++){
      timer += min(tickets[i], tickets[k]-1);
  }
  return timer;
}

void displayQueue(queue<int> q){
  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }cout<<endl;
}

void printEveryKWindow(vector<int> &arr, int k){
  queue<int> q;
  for(int i = 0; i < k-1; i++) q.push(arr[i]);

  for(int i = k-1; i < arr.size(); i++){
    q.push(arr[i]);
    displayQueue(q);
    q.pop();
  }
}

vector<int> firstNegativeEveryKWindow(vector<int> &arr, int k){
  vector<int> ans;
  queue<int> q;
  for(int i = 0; i < k-1; i++){
    if(arr[i] < 0){
      q.push(i);
    }
  }

  for(int i = k-1; i < arr.size(); i++){
    if(arr[i] < 0) q.push(i);
    if(!q.empty() && q.front() <= i-k) q.pop();
    if(q.empty()) ans.push_back(0);
    else ans.push_back(arr[q.front()]);
  }
}

string firstNonRepeatingChar(string A) {
  string ans = "";
  vector<int> count(26, 0);
  queue<char> q;
  for(int i = 0; i < A.size(); i++){
    count[A[i]-'a']++;
    if(count[A[i]-'a'] < 2)
      q.push(A[i]);
    while(!q.empty() && count[q.front() - 'a'] >= 2) q.pop();
    if(q.empty()) ans.push_back('#');
    else ans.push_back(q.front());
  }
  return ans;
}

vector<int> maximumInEveryWindow(vector<int> &nums, int k){
  vector<int> ans;
  deque<int> dq;
  for(int i = 0; i < k-1; i++){
    while(!dq.empty() && nums[dq.back()] < nums[i]){
      dq.pop_back();
    }
    dq.push_back(i);
  }
  for(int i = k-1; i < nums.size(); i++){
    while(!dq.empty() && nums[dq.back()] < nums[i]){
      dq.pop_back();
    }
    dq.push_back(i);
    while(!dq.empty() && dq.front() <= i-k){
      dq.pop_front();
    }
    ans.push_back(nums[dq.front()]);
  }
  return ans;
}

int minKBitFlips(vector<int> &nums, int k){
  int flip = 0, n = nums.size();
  for(int i = 0; i < n; i++){
    if(nums[i] == 0){
      if(i+k-1 >= n) return -1;
      for(int j = i; j <= i+k-1; j++){
        nums[j] = !nums[j];
      }
      flip++;
    }
  }
  return flip;
}

int minKBitFlips2(vector<int> &nums, int k){
  int flip = 0, n = nums.size();
  queue<int> q;

  for(int i = 0; i < n; i++){
    while(!q.empty() && q.front() < i){
      q.pop();
    }
    int size = q.size() % 2;
    if((nums[i] == 0 && size == 0) || (nums[i] == 1 && size == 1)){
      if(i+k-1 >= n) return -1;
      q.push(i+k-1);
      flip++;
    }
  }
  return flip;
}

int main() {
  vector<int> arr ={1, 2, 3, 4, 5};
  printEveryKWindow(arr, 3);
  return 0;
}
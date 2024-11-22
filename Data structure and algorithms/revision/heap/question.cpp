#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

int height(vector<int> &heap){
  int size = heap.size();
  if(size == 1) return 1;
  int height = 0;
  while(size > 1){
    height++;
    size /= 2;
  }
  return height;
}

long long minCost(vector<long long>& arr) {
  priority_queue <long long, vector<long long>, greater<long long> > pq; 
  for(int i = 0; i < arr.size(); i++){
    pq.push(arr[i]);
  }
  long long sum = 0;
  while(pq.size() > 1){
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    int c = a+b;
    sum += c;
    pq.push(c);
  }
  return sum;
}

int maxChoxolate(int A, vector<int> &B){
  priority_queue <long long> pq; 
  for(int i = 0; i < B.size(); i++) pq.push(B[i]);
  long long ans = 0;
  for(int i = 0; (i < A && (!pq.empty())); i++){
    int ch = pq.top(); pq.pop();
    ans = ans + ch;
    if(ch/2)pq.push(ch/2);
  }
  return ans % 1000000007;
}

int kthSmallest(vector<int> &arr, int k){
  priority_queue<int> pq;
  for(int i = 0; i < k; i++){
    pq.push(arr[i]);
  }
  for(int i = k; i < arr.size(); i++){
    if(arr[i] < pq.top()){
      pq.pop();
      pq.push(arr[i]);
    }
  }
  return pq.top();
}

int findKthLargest(vector<int>& nums, int k) {
  priority_queue <int, vector<int>, greater<int> > pq; 
  for(int i = 0; i < k; i++){
    pq.push(nums[i]);
  }
  for(int i = k; i < nums.size(); i++){
    if(nums[i] > pq.top()){
      pq.pop();
      pq.push(nums[i]);
    }
  }
  return pq.top();
}

vector<int> kthLargest(int k, int arr[], int n) {
  priority_queue <int, vector<int>, greater<int> > pq; 
  vector<int> ans;
  for(int i = 0; i < k; i++){
    pq.push(arr[i]);
    if(pq.size() == k){
      ans.push_back(pq.top());
    }else{
      ans.push_back(-1);
    }
  }
  for(int i = k; i < n; i++){
    if(arr[i] > pq.top()){
      pq.pop();
      pq.push(arr[i]);
    }
    ans.push_back(pq.top());
  }
  return ans;
}

long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2){
  priority_queue<long long> p1, p2;
  long long s1 = 0, s2 = 0;
  for(long long i = 0; i < K1; i++){
    s1 += A[i];
    p1.push(A[i]);
  }
  for(long long i = 0; i < K2-1; i++){
    s2 += A[i];
    p2.push(A[i]);
  }
  
  for(long long i = K1; i < N; i++){
    if(A[i] < p1.top()){
      s1 -= p1.top();
      p1.pop();
      s1 += A[i];
      p1.push(A[i]);
    }
  }
  for(long long i = K2-1; i < N; i++){
    if(A[i] < p2.top()){
      s2 -= p2.top();
      p2.pop();
      s2 += A[i];
      p2.push(A[i]);
    }
  }
  return s2-s1;
}

void heapify(vector<int> &arr, int idx, int n){
  int largest = idx;
  int left = (2*idx)+1;
  int right = (2*idx)+2;
  
  if(left < n && arr[left] > arr[largest])
  largest = left;
  if(right < n && arr[right] > arr[largest])
  largest = right;
  
  if(largest != idx){
    swap(arr[idx], arr[largest]);
    heapify(arr, largest, n);
  }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
  vector<int> ans;
  for(int i = 0; i < n; i++)
  ans.push_back(a[i]);
  
  for(int i = 0; i < m; i++)
  ans.push_back(b[i]);
  
  n = ans.size();
  for(int i = n/2-1; i >= 0; i--){
    heapify(ans, i, n);
  }
  return ans;
}

int countNode(struct Node* tree){
    if(!tree) return 0;
    int left = countNode(tree->left);
    int right = countNode(tree->right);
    return left+right+1;
}
bool checkCBT(struct Node* tree, int idx, int count){
  if(!tree) return true;
  if(idx >= count) return false;
  bool left = checkCBT(tree->left, 2*idx+1, count);
  if(!left) return false;
  bool right = checkCBT(tree->right, 2*idx+2, count);
  return right;
}
bool checkHeap(struct Node* tree){
  if(!tree) return true;
  bool left = checkHeap(tree->left);
  bool right = checkHeap(tree->right);
  bool curr = true;
  if(tree->left){
    if(tree->data < tree->left->data) curr = false;
  }
  if(tree->right){
    if(tree->data < tree->right->data) curr = false;
  }
  return curr && left && right;
}
bool isHeap(struct Node* tree) {
  int count = countNode(tree);
  bool isCBT = checkCBT(tree, 0, count);
  if(!isCBT) return false;
  return checkHeap(tree);
}

void inorder(Node* root, vector<int> &arr){
  if(!root) return;
  inorder(root->left, arr);
  arr.push_back(root->data);
  inorder(root->right, arr);
}
void postorder(Node* root, vector<int> &in, int &i){
  if(!root) return;
  postorder(root->left, in, i);
  postorder(root->right, in, i);
  root->data = in[i++];
}
void convertToMaxHeapUtil(Node* root){
  vector<int> in;
  int i = 0;
  inorder(root, in);
  postorder(root, in, i);
}


class ListNode{
  public:
  int data;
  ListNode* next;
  ListNode(int data){
    this->data = data;
    this->next = NULL;
  }
};
class Compare{
  public:
  bool operator()(ListNode* a, ListNode* b){
    return a->data > b->data;
  }
};

ListNode *mergeKSortedList(vector<ListNode*> &arr){
  vector<ListNode*> temp;
  for(int i = 0; i < arr.size(); i++){
    temp.push_back(arr[i]);
  }

  priority_queue<ListNode*, vector<ListNode*>, Compare> pq(temp.begin(), temp.end());
  ListNode* head = new ListNode(0);
  ListNode * tail = head;
  while(!pq.empty()){
    tail->next = pq.top(); pq.pop();
    tail = tail->next;
    if(tail->next){
      pq.push(tail->next);
    }
  }
  tail = head;
  head = head->next;
  delete tail;
  return head;
}

vector<int> mergeKSortedArray(vector<vector<int>> &arr, int k){
  vector<pair<int, pair<int, int>>> temp;
  for(int i = 0; i < k; i++){
    temp.push_back({arr[i][0], {i, 0}});
  }

  vector<int> ans;
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq(temp.begin(), temp.end());
  while(!pq.empty()){
    pair<int, pair<int, int>> top = pq.top(); pq.pop();
    ans.push_back(top.first);
    int row = top.second.first;
    int col = top.second.second;
    if(col+1 < k){
      pq.push({arr[row][col+1],{row, col+1}});
    }
  }
  return ans;
}

vector<int> smallestRangeKList(vector<vector<int>> &nums){
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  int mini, maxi = -100000, currRange = 100000;
  for(int i = 0; i < nums.size(); i++){
    pq.push({nums[i][0], {i, 0}});
    maxi = max(nums[i][0], maxi);
  }

  vector<int> ans(2);
  while(true){
    pair<int, pair<int, int>> top = pq.top(); pq.pop();
    int mini = top.first;
    int row = top.second.first;
    int col = top.second.second;

    if(maxi - mini < currRange){
      ans[0] = mini;
      ans[1] = maxi;
      currRange = maxi - mini;
    }
    if(col+1 < nums[row].size()){
      maxi = max(maxi, nums[row][col+1]);
      pq.push({nums[row][col+1],{row, col+1}});
    }else{
      break;
    }
  }
  return ans;
}

bool isPossible(vector<int>& arr) {
  long long sum = 0;
  priority_queue<long long>p;
  for(int i = 0; i < arr.size(); i++){
    p.push(arr[i]);
    sum += arr[i];
  }

  long long elem, remSum, maxElem;
  while(p.top() != 1){
    maxElem = p.top(); p.pop();
    remSum = sum - maxElem;
    if(remSum <= 0 || remSum >= maxElem){
      return false;
    }
    elem = maxElem % remSum;
    sum = remSum + elem;
    if(elem == 0){
      if(remSum == 1) return 1;
      else return 0;
    }
    p.push(elem);
  }
  return true;
}

int main() {
  

  return 0;
}
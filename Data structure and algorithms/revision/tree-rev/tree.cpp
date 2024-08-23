#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm> 

using namespace std;

class Node{
  public:
  int data;
  Node *left, *right;
  Node(int data){
    this->data = data;
    left = right = NULL;
  }
};

void levelOrderTraversal(Node* root){
  queue<Node*> q;
  q.push(root);
  cout<<"\nLevel Order Traversal\n";
  while(!q.empty()){
    Node* temp = q.front(); q.pop();
    cout<<temp->data<<" ";
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
  }
  cout<<endl;
}

void preorder(Node* root){
  if(!root) return;
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node* root){
  if(!root) return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void postorder(Node* root){
  if(!root) return;
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}

Node* createTree(){
  int data;
  cout<<"Enter data : ";
  cin>> data;
  if(data == -1) return NULL;
  Node* root = new Node(data);
  cout<<"Enter left of "<<data<<endl;
  root->left = createTree();
  cout<<"Enter right of "<<data<<endl;
  root->right = createTree();
  return root;
}

Node* createTreeLevelOrder(vector<int> &data, Node* root){
  queue<Node*> q;
  int i = 0;
  root = new Node(data[i++]);
  q.push(root);

  while(!q.empty()){
    Node* temp = q.front(); q.pop();
    if(data[i] != -1){
      temp->left = new Node(data[i++]);
      q.push(temp->left);
    }else{ i++;}
    if(data[i] != -1){
      temp->right = new Node(data[i++]);
      q.push(temp->right);
    }else {i++;}

    if(i >= data.size()) break;
  }
  return root;
}

bool isIdentical(Node* r1, Node* r2){
  if(!r1 && !r2) return true;
  if(!r1 || !r2) return false;
  bool curr = r1->data == r2->data;
  return (curr && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right));
}

Node* mirror(Node* root){
  if(!root) return NULL;
  Node* r = new Node(root->data);
  r->left = mirror(root->right);
  r->right = mirror(root->left);
  return r;
}

void solveMirror(Node* root){
  if(!root) return;
  Node* temp = root->right;
  root->right = root->left;
  root->left = temp;
  solveMirror(root->left);
  solveMirror(root->right);
}
Node* mirror2(Node* root){
  solveMirror(root);
  return root;
}

pair<bool, int>balanceSolved(Node* root){
  if(!root) return {true, 0};
  pair<bool, int> left = balanceSolved(root->left);
  pair<bool, int> right = balanceSolved(root->right);
  bool below = left.first && right.first;
  int bf = abs(left.second - right.second) <= 1;
  return {below && bf, max(left.second, right.second) + 1};
}

bool isBalanced(Node* root){
  return balanceSolved(root).first;
}

vector<int> spiralPrint(Node* root){
  stack<Node*> rl, lr;
  bool isRL = true;
  vector<int> ans;
  Node* temp;
  rl.push(root);

  while(!(rl.empty() && lr.empty())){
    if(isRL){
      while(!rl.empty()){
        temp = rl.top(); rl.pop();
        ans.push_back(temp->data);
        if(temp->right) lr.push(temp->right);
        if(temp->left) lr.push(temp->left);
      }
      isRL = false;
    }else{
      while(!lr.empty()){
        temp = lr.top(); lr.pop();
        ans.push_back(temp->data);
        if(temp->left) rl.push(temp->left);
        if(temp->right) rl.push(temp->right);
      }
      isRL = true;
    }
  }
  return ans;
}

bool isCousinMineVersion(Node* root, int a, int b){
  queue<Node*>q;
  unordered_map<int, Node*> map;
  int count = 0;
  Node *temp, *parent = NULL;
  q.push(root); q.push(NULL);
  map[root->data] = NULL;

  while(q.size() != 1){
    while(q.front() != NULL){
      temp = q.front(); q.pop();
      if(temp->left){
        q.push(temp->left);
        map[temp->left->data] = temp;
      }
      if(temp->right){
        q.push(temp->right);
        map[temp->right->data] = temp;
      }
      if(temp->data == a || temp->data == b){
        if(!parent){
          parent = map[temp->data];
          count++;
        }else if(parent != map[temp->data]) count++;
      }
    }
    if(count == 2) return true;
    if(!q.front()){
      count = 0;
      parent = NULL;
      q.pop();
      q.push(NULL);
    }
  }
  return false;
}

bool isSameParent(Node* root, int a, int b){
  if(!root) return false; 
  if(root->left && root->right){
    int l = root->left->data, r = root->right->data;
    if((l == a || l == b) && (r == a || r == b)) return true;
  }
  return isSameParent(root->left, a, b) || isSameParent(root->right, a, b);
}
bool isCousin(Node* root, int a, int b){
  queue<Node*>q;
  int count = 0;
  Node* temp;
  q.push(root); q.push(NULL);

  while(q.size() != 1){
    while(q.front() != NULL){
      temp = q.front(); q.pop();
      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);
      if(temp->data == a || temp->data == b) count++;
    }
    if(count == 2) return !isSameParent(root, a, b);
    if(!q.front()){
      count = 0;
      q.pop();
      q.push(NULL);
    }
  }
  return false;
}

vector<int>leftView(Node* root){
  vector<int> ans;
  queue<Node*> q;
  Node* temp;
  bool isFirst = true;
  q.push(root); q.push(NULL);

  while(q.size() != NULL){
    temp = q.front(); q.pop();
    if(!temp){
      q.push(NULL);
      isFirst = true;
    }else{
      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);
      if(isFirst){
        ans.push_back(temp->data);
        isFirst = false;
      }
    }
  }
  return ans;
}

void leftViewSolve(Node *root, vector<int> &ans, int level){
  if(!root) return;
  if(ans.size() == level) ans.push_back(root->data);
  leftViewSolve(root->left, ans, level+1);
  leftViewSolve(root->right, ans, level+1);
}
vector<int> leftView2(Node* root){
  vector<int> ans;
  leftViewSolve(root, ans, 0);
  return ans;
}


vector<int>rightView(Node* root){
  vector<int> ans;
  queue<Node*> q;
  Node* temp;
  bool isFirst = true;
  q.push(root); q.push(NULL);

  while(q.size() != NULL){
    temp = q.front(); q.pop();
    if(!temp){
      q.push(NULL);
      isFirst = true;
    }else{
      if(temp->right) q.push(temp->right);
      if(temp->left) q.push(temp->left);
      if(isFirst){
        ans.push_back(temp->data);
        isFirst = false;
      }
    }
  }
  return ans;
}

void rightViewSolve(Node *root, vector<int> &ans, int level){
  if(!root) return;
  if(ans.size() == level) ans.push_back(root->data);
  rightViewSolve(root->right, ans, level+1);
  rightViewSolve(root->left, ans, level+1);
}
vector<int> rightView2(Node* root){
  vector<int> ans;
  rightViewSolve(root, ans, 0);
  return ans;
}

void minMax(Node* root, int p, int &l, int &r){
  if(!root) return;
  l = min(l, p);
  r = max(r, p);
  minMax(root->left, p-1,l, r);
  minMax(root->right, p+1,l, r);
}
vector<int> topView(Node* root){
  int l = 0, r = 0;
  minMax(root, 0, l, r);
  vector<int> ans(r-l+1);
  vector<bool> vis(r-l+1, false);
  queue<pair<Node*, int>> q;
  q.push({root, -l});

  while(!q.empty()){
    Node* node = q.front().first;
    //here idx is hd after arranging (0-max, not like nev to pos)
    int idx = q.front().second;
    q.pop();
    if(!vis[idx]){
      ans[idx] = node->data;
      vis[idx] = true;
    }
    if(node->left) q.push({node->left, idx-1});
    if(node->right) q.push({node->right, idx+1});
  }
  return ans;
}
void topView2Solve(Node* root, vector<int> &ans, vector<int> &level, int hd, int l){
  if(!root) return;
  if(l < level[hd]){
    ans[hd] = root->data;
    level[hd] = l;
  }
  topView2Solve(root->left, ans, level, hd-1, l+1);
  topView2Solve(root->right, ans, level, hd+1, l+1);
}
vector<int> topView2(Node* root){
  int l = 0, r = 0;
  minMax(root, 0, l, r);
  vector<int> ans(r-l+1);
  vector<int> level(r-l+1, __INT32_MAX__);
  topView2Solve(root, ans, level, -l, 0);
  return ans;
}

vector<int> preorderIterative(Node* root){
  vector<int> ans;
  stack<Node*> st;
  st.push(root);
  while(!st.empty()){
    Node* top = st.top();
    st.pop();
    ans.push_back(top->data);
    if(top->right) st.push(top->right);
    if(top->left) st.push(top->left);
  }
  return ans;
}

vector<int> inorderIterative(Node* root){
  vector<int> ans;
  stack<Node*> st;
  unordered_map<Node*, bool> map;
  while(!st.empty()){
    Node* top = st.top();
    if(top->left && !map[top]){
      st.push(top->left);
      map[top] = true;
    }else{
      ans.push_back(top->data);
      st.pop();
      if(top->right) st.push(top->right);
    }
  }
  return ans;
}

vector<int> postorderIterative(Node* root){
  vector<int> ans;
  stack<Node*> st;
  st.push(root);
  while(!st.empty()){
    Node* top = st.top();
    st.pop();
    ans.push_back(top->data);
    if(top->left) st.push(top->left);
    if(top->right) st.push(top->right);
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  // vector<int> data = {1,2,3,4,5,6,7,8,-1,9,10,-1,-1,-1,-1};
  vector<int> data = {1,2,3,4,-1,5,-1,6,-1,-1,-1};
  Node* root = createTreeLevelOrder(data, NULL);

  // levelOrderTraversal(root);
  // inorder(root);
  // cout<<endl;
  // preorder(root);
  // cout<<endl;
  // postorder(root);
  // cout<<endl;

  // Node* root = createTree();
  // levelOrderTraversal(root);

  // Node* root1 = createTreeLevelOrder(data, NULL);
  // Node* root2 = createTreeLevelOrder(data, NULL);
  // cout<<isIdentical(root1, root2)<<endl;

  // inorder(root);
  // cout<<endl;
  // Node* r = mirror(root);
  // Node* r = mirror2(root);
  // inorder(r);
  // cout<<endl;

  // cout<<isBalanced(root)<<endl;

  vector<int> ans = spiralPrint(root);
  for(int i = 0; i < ans.size(); i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;

  return 0;
}
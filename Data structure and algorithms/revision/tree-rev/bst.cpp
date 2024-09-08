#include <iostream>
#include <vector>
using namespace std;

class Node{
  public:
  int data;
  Node *left, *right;
  Node(int d){
    data = d;
    left = right = NULL;
  }
};

class ListNode{
  public:
  int data;
  ListNode *next;
  ListNode(int data){
    this->data = data;
    next = NULL;
  }
};

Node* insertIntoBST(Node* root, int data){
  if(!root){
    return new Node(data);
  }
  if(data < root->data)
    root->left = insertIntoBST(root->left, data);
  else
    root->right = insertIntoBST(root->right, data);

  return root;
}

void inorder(Node* root){
  if(!root) return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

bool search(Node* root, int key){
  if(!root) return false;
  if(root->data == key) return true;
  else if(root->data > key) return search(root->left, key);
  return search(root->right, key);
}

Node* deleteFromBst(Node* root, int key){
  if(!root) return NULL;
  if(key < root->data){
    root->left = deleteFromBst(root->left, key);
    return root;
  }else if(key > root->data){
    root->right = deleteFromBst(root->right, key);
    return root;
  }else{
    if(!root->left && !root->right){
      delete root;
      return NULL;
    }
    if(!root->right){
      Node* temp = root->left;
      delete root;
      return temp;
    }
    if(!root->left){
      Node* temp = root->right;
      delete root;
      return temp;
    }
    if(root->left && root->right){
      Node* parent = root;
      Node* child = root->left;
      
      while(child->right){
        parent = child;
        child = child->right;
      }
      
      if(parent != root){
        Node* temp = child->left;
        parent->right = temp;
        child->left = root->left;
        child->right = root->right;
      }else{
        child->right = parent->right;
      }
      delete root;
      return child;
    }
  }
}

void inorderData(Node* root, vector<int> &in){
  if(!root) return;
  inorderData(root->left, in);
  in.push_back(root->data);
  inorderData(root->right, in);
}
bool isBST(Node* root) {
  vector<int> in;
  inorderData(root, in);
  for(int i = 1; i < in.size(); i++){
    if(in[i] <= in[i-1]){
      return false;
    }
  }
  return true;
}
 void inorderAgain(Node* root, int &prev, bool &flag){
  if(!root) return;
  inorderAgain(root->left, prev, flag);
  if(root->data <= prev){
    flag = false;
    return;
  }
  prev = root->data;
  inorderAgain(root->right, prev, flag);
 }
bool isBST2(Node* root){
  int prev = -1;
  bool flag = true;
  inorderAgain(root, prev, flag);
  return flag;
}

void inorder3(Node* root, int &prev, int &ans){
  if(!root) return;
  inorder3(root->left, prev, ans);
  ans = min(ans, abs(prev-root->data));
  prev = root->data;
  inorder3(root->right, prev, ans);
}
int minDiffInBST(Node* root) {
  int prev = -100000;
  int ans = 100000;

  inorder3(root, prev, ans);
  return ans;
}

void inorder4(Node* root, int &ans, int &k){
  if(k==0 || !root) return;
  inorder4(root->left, ans, k);
  if(k > 0){
    ans += root->data;
    k--;
  }
  inorder4(root->right, ans, k);
}
int sum(Node* root, int k) { 
  int ans = 0;
  inorder4(root, ans, k);
  return ans;
} 

void inorder4(Node* root, int &ans, int &k){
  if(k <= 0 || !root) return;
  inorder4(root->right, ans, k);
  k--;
  if(k == 0){
    ans = root->data;
    return;
  }
  inorder4(root->left, ans, k);
}
int kthLargest(Node *root, int K){
  int ans = 0;
  inorder4(root, ans, K);
  return ans;
}

Node* createBSTPreorderSolve(vector<int> &pre, int mini, int maxi, int &i){
  if(i >= pre.size() || (pre[i] < mini || pre[i] > maxi)) return NULL;
  Node* root = new Node(pre[i++]);
  root->left = createBSTPreorderSolve(pre, mini, root->data, i);
  root->right = createBSTPreorderSolve(pre, root->data, maxi, i);
  return root;
}
Node* createBSTFromPreorder(vector<int> &pre){
  int mini = -10000, maxi = 10000, i = 0;
  return createBSTPreorderSolve(pre, mini, maxi, i);
}

Node* createBSTPostorderSolve(vector<int> &post, int mini, int maxi, int &i){
  if(i < 0 || (post[i] < mini || post[i] > maxi)) return NULL;
  Node* root = new Node(post[i--]);
  root->right = createBSTPostorderSolve(post, root->data, maxi, i);
  root->left = createBSTPostorderSolve(post, mini, root->data, i);
  return root;
}
Node* createBSTFromPostorder(vector<int> &post){
  int mini = -10000, maxi = 10000, i = post.size()-1;
  return createBSTPostorderSolve(post, mini, maxi, i);
}

Node* LCA(Node *root, int n1, int n2){
  if(!root) return NULL;
  if(root->data < n1 && root->data < n2)
    return LCA(root->right, n1, n2);
  else if(root->data > n1 && root->data > n2)
    return LCA(root->left, n1, n2);
  return root;
}

Node* LLToBSTSolve(vector<int> &arr, int s, int e){
  if(s > e) return NULL;
  int mid = (s+e)/2;
  Node* node = new Node(arr[mid]);
  node->left = LLToBSTSolve(arr, s, mid-1);
  node->right = LLToBSTSolve(arr, mid+1, e);
  return node;
}
Node* LLToBST(ListNode *head){
  vector<int> arr;
  ListNode* temp = head;
  while(temp){
    arr.push_back(temp->data);
    temp = temp->next;
  }
  return LLToBSTSolve(arr, 0, arr.size()-1);
}

void inorderForMerge(Node* root, vector<int> &arr){
  if(!root) return;
  inorderForMerge(root->left, arr);
  arr.push_back(root->data);
  inorderForMerge(root->right, arr);
}
vector<int>mergeTwoSortedVector(vector<int> &v1, vector<int> &v2){
  int s1 = v1.size(), s2 = v2.size();
  vector<int> ans(s1+s2);
  int i = 0, j = 0, k = 0;
  
  while(i < s1 && j <  s2){
    if(v1[i] < v2[j]) ans[k++] = v1[i++];
    else if(v1[i] > v2[j]) ans[k++] = v2[j++];
    else{
      ans[k++] = v1[i++];
      ans[k++] = v2[j++];
    }
  }
  while(i < s1) ans[k++] = v1[i++];
  while(j < s2) ans[k++] = v2[j++];
  return ans;
}
vector<int> mergeTwoBST(Node *root1, Node *root2) {
  vector<int> v1, v2;
  inorderForMerge(root1, v1);
  inorderForMerge(root2, v2);
  return mergeTwoSortedVector(v1, v2);
}

void correctBST(Node* root){
  Node* first = NULL, *second = NULL, *prev = NULL, *curr = root;
  while(curr){
    if(curr->left){
      Node* temp = curr->left;
      while(temp->right && temp->right != curr){
        temp = temp->right;
      }
      if(!temp->right){
        temp->right = curr;
        curr = curr->left;
      }else{
        if(!prev) prev = curr;
        else{
          if(prev->data > curr->data){
            if(!first) first = prev;
            second = curr;
          }
        }
        prev = curr;
        curr = curr->right;
        temp->right = NULL;
      }
    }else{
      if(!prev) prev = curr;
      else{
        if(prev->data > curr->data){
          if(!first) first = prev;
          second = curr;
        }
      }
      prev = curr;
      curr = curr->right;
    }
  }
  int temp = first->data;
  first->data = second->data;
  second->data = temp;
}

int main() {
  Node* root = NULL;
  root = insertIntoBST(root, 10);
  root = insertIntoBST(root, 8);
  root = insertIntoBST(root, 20);
  root = insertIntoBST(root, 15);
  root = insertIntoBST(root, 6);
  cout<<search(root, 6)<<endl;
  cout<<search(root, 20)<<endl;
  cout<<search(root, 100)<<endl;
  inorder(root);
  cout<<endl;
  return 0;
}
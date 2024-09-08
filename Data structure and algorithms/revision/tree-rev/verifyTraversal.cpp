#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* left, *right;
  Node(int d){
    data = d;
    left = right = NULL;
  }
};

int findIndex(int* arr, int s, int e, int element){
  for(int i = s; i <= e; i++){
    if(element ==arr[i]) return i;
  }
  return -1;
}
Node* inorderPreorder(int *in, int *pre, int s, int e, int &i, bool &flag){
  if(s > e) return NULL;
  int idx = findIndex(in, s, e, pre[i]);
  if(idx == -1){
    flag = false;
    return NULL;
  }
  Node* node = new Node(pre[i++]);
  node->left = inorderPreorder(in, pre, s, idx-1, i, flag);
  node->right = inorderPreorder(in, pre, idx+1, e, i, flag);
  return node;
}

Node* inorderPostorder(int *in, int *post, int s, int e, int &i, bool &flag){
  if(s > e) return NULL;
  int idx = findIndex(in, s, e, post[i]);
  if(idx == -1){
    flag = false;
    return NULL;
  }
  Node* node = new Node(post[i--]);
  node->right = inorderPostorder(in, post, idx+1, e, i, flag);
  node->left = inorderPostorder(in, post, s, idx-1, i, flag);
  return node;
}

bool isIdentical(Node* r1, Node* r2){
  if(!r1 && !r2) return true;
  if(!r1 || !r2) return false;
  bool curr = r1->data == r2->data;
  return (curr && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right));
}

bool checktree(int preorder[], int inorder[], int postorder[], int N) { 
  int idx1 = 0, idx2 = N-1;
  bool flag1 = true, flag2 = true;
  
  Node *r1 = inorderPreorder(inorder, preorder, 0, N-1, idx1, flag1);
  if(!flag1) return false;
  
  Node *r2 = inorderPostorder(inorder, postorder, 0, N-1, idx2, flag2);
  if(!flag2) return false;
  
  return isIdentical(r1, r2);
} 

int main() {
  int n = 5;
  int preorder[] = {1, 2, 4, 5, 3};
  int inorder[] = {4, 2, 5, 1, 3};
  int postorder[] = {4, 5, 2, 3, 1};
  bool isOkay = checktree(preorder, inorder, postorder, n);
  if(isOkay) cout<<"YESSS!! all the traversal are of same tree"<<endl;
  else cout<<"NO!! all the traversal are not of same tree"<<endl;
  return 0;
}
#include <iostream>
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

int solveBurningNode(Node* root, int &target, int &ans, Node* &burnNode){
  if(!root) return 0;
  if(root->data == target){
    burnNode = root;
    return-1;
  }
  int left = solveBurningNode(root->left, target, ans, burnNode);
  int right = solveBurningNode(root->right, target, ans, burnNode);

  if(left < 0){
    ans = max(ans, abs(left)+right);
    return left-1;
  }
  if(right < 0){
    ans = max(ans, abs(right)+left);
    return right-1;
  }
  return 1+ max(left, right);
}

int getHeight(Node* root){
  if(!root) return 0;
  return 1 + max(getHeight(root->left), getHeight(root->right));
}

int minTimeToBurnTree(Node* root, int target){
  int ans = -1;
  Node* burnNode = NULL;
  solveBurningNode(root, target, ans, burnNode);
  int height = getHeight(burnNode)-1;
  return max(ans, height);
}

int solveMaxSumPath(Node* root, int &ans){
  if(!root) return 0;
  if(!root->left && !root->right) return root->data;
  int left = solveMaxSumPath(root->left, ans);
  int right = solveMaxSumPath(root->right, ans);

  if(root->left && root->right){
    ans = max(ans, root->data+left+right);
    return root->data + max(left, right);
  }
  if(root->left) return root->data+left;
  return root->data+right;
}
int maxSumPath(Node* root){
  int ans = -1000000;
  int val = solveMaxSumPath(root, ans);
  if(root->left && root->right) return ans;
  return max(ans, val);
}

int main() {
  
  return 0;
}
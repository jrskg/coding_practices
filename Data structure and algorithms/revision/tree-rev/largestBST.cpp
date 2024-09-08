#include <iostream>
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

class Data{
  public:
  bool isBst;
  int size, mini, maxi;
  Data(bool isBst, int size, int mini, int maxi){
    this->isBst = isBst;
    this->size = size;
    this->mini = mini;
    this->maxi = maxi;
  }
};

Data* solve(Node* root, int &count){
  if(!root->left && !root->right) return new Data(true, 1, root->data, root->data);
  else if(!root->right && root->left){
    Data* left = solve(root->left, count);
    if(left->isBst && left->maxi < root->data){
      count = max(count, left->size+1);
      return new Data(true, left->size+1, left->mini, root->data);
    }else return new Data(false, 0,0,0);
  }else if(!root->left && root->right){
    Data* right = solve(root->right, count);
    if(right->isBst && right->mini > root->data){
      count = max(count, right->size+1);
      return new Data(true, right->size+1, root->data, right->maxi);
    }else return new Data(false, 0,0,0);
  }else{
    Data* left = solve(root->left, count);
    Data* right = solve(root->right, count);
    if((left->isBst && right->isBst) && (left->maxi < root->data && right->mini > root->data)){
      count = max(count, left->size+right->size+1);
      return new Data(true, left->size+right->size+1, left->mini, right->maxi);
    }else return new Data(false, 0,0,0);
  }
}


class Data2{
  public:
  bool isBst;
  int size, mini, maxi;
  Data2(){
    isBst = true;
    size = 0;
    mini = 10000;
    maxi = -10000;
  }
};
Data2* solve2(Node* root, int &count){
  if(!root) return new Data2();
  Data2* left = solve2(root->left, count);
  Data2* right = solve2(root->right, count);

  if(left->isBst && right->isBst && left->maxi < root->data && right->mini > root->data){
    Data2* head = new Data2();
    head->size = left->size+right->size+1;
    head->mini = min(left->mini, root->data);
    head->maxi = max(right->maxi, root->data);
    count = max(count, head->size);
    return head;
  }
  left->isBst = false;
  return left;
}

int largestBst(Node *root){
  int count = 1;
  solve(root, count);
  return count;
}

int main() {
  

  return 0;
}
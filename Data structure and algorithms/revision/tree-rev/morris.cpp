#include <iostream>
#include <vector>
// #include <queue>
// #include <stack>
// #include <unordered_map>
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

vector<int> inorderMorris(Node* root){
  vector<int> ans;
  Node* curr = root;
  while(curr){
    if(curr->left){
      Node* temp = curr->left;
      while(temp->right && temp->right != curr) temp = temp->right;
      if(!temp->right){
        temp->right = curr;
        curr = curr->left;
      }else if(temp->right == curr){
        ans.push_back(curr->data);
        temp->right = NULL;
        curr = curr->right;
      }
    }else{
      ans.push_back(curr->data);
      curr = curr->right;
    }
  }
  return ans;
}

vector<int> preorderMorris(Node* root){
  vector<int> ans;
  Node* curr = root;
  while(curr){
    if(curr->left){
      Node* temp = curr->left;
      while(temp->right && temp->right != curr) temp = temp->right;
      if(!temp->right){
        temp->right = curr;
        ans.push_back(curr->data);
        curr = curr->left;
      }else if(temp->right == curr){
        temp->right = NULL;
        curr = curr->right;
      }
    }else{
      ans.push_back(curr->data);
      curr = curr->right;
    }
  }
  return ans;
}

vector<int> postorderMorris(Node* root){
  vector<int> ans;
  Node* curr = root;
  while(curr){
    if(curr->right){
      Node* temp = curr->right;
      while(temp->left && temp->left != curr) temp = temp->left;
      if(!temp->left){
        ans.push_back(curr->data);
        temp->left = curr;
        curr = curr->right;
      }else if(temp->left == curr){
        temp->left = NULL;
        curr = curr->left;
      }
    }else{
      ans.push_back(curr->data);
      curr = curr->left;
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

Node* flattenBinaryTreeToLL(Node* root){
  Node *curr = root, *temp;
  while(curr){
    if(curr->left){
      temp = curr->left;
      while(temp->right) temp = temp->right;
      temp->right = curr->right;
      curr->right = curr->left;
      curr->left = NULL;
    }
    curr = curr->right;
  }
  return root; 
}

int main() {
  
  return 0;
}
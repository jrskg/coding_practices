#include <iostream>
#include <queue>
using namespace std;

class Node{
  public:
  int data, height;
  Node *left, *right;
  Node(int d){
    data = d;
    height = 1;
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

int getHeight(Node* root){
  return root ? root->height : 0;
}

Node* rightRotate(Node* root){
  Node* leftch = root->left;
  Node* childs = leftch->right;
  leftch->right = root;
  root->left = childs;
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  leftch->height = 1 + max(getHeight(leftch->left), getHeight(leftch->right));
  return leftch;
}

Node* leftRotate(Node* root){
  Node* rightch = root->right;
  Node* childs = rightch->left;
  rightch->left = root;
  root->right = childs;
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  rightch->height = 1 + max(getHeight(rightch->left), getHeight(rightch->right));
  return rightch;
}
Node* insert(Node* root, int data){
  if(!root) return new Node(data);
  if(data < root->data) root->left = insert(root->left, data);
  else if(data > root->data) root->right = insert(root->right, data);
  else return root;

  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  int bf = getHeight(root->left) - getHeight(root->right);

  if(bf > 1 && data < root->left->data){
    // LL
    return rightRotate(root);
  }else if(bf > 1 && data > root->left->data){
    //LR
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }else if(bf < -1 && data > root->right->data){
    //RR
    return leftRotate(root);
  }else if(bf < -1 && data < root->right->data){
    //RL
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}

Node* deleteNode(Node* root, int data){
  if(!root) return NULL;
  if(data < root->data){
    root->left = deleteNode(root->left, data);
  }else if(data > root->data){
    root->right = deleteNode(root->right, data);
  }else{
    if(!root->left && !root->right){
      delete root;
      return NULL;
    }
    else if(root->left && !root->right){
      Node* temp = root->left;
      delete root;
      return temp;
    }
    else if(!root->left && root->right){
      Node* temp = root->right;
      delete root;
      return temp;
    }
    else if(root->left && root->right){
      Node* temp = root->right;
      while(temp->left) temp = temp->left;
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  int bf = getHeight(root->left) - getHeight(root->right);
  if(bf > 1){
    if(getHeight(root->left->left) - getHeight(root->left->right) < 0){
      // LR
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }else{
      //LL
      return rightRotate(root);
    }
  }else if(bf < -1){
    if(getHeight(root->right->left) - getHeight(root->right->right) > 0){
      //RL
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }else{
      // RR
      return leftRotate(root);
    }
  }
  return root;
}

int main() {
  Node* root = NULL;
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 60);
  root = insert(root, 70);
  levelOrderTraversal(root);
  return 0;
}
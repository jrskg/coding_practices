#include <iostream>
using namespace std;

class Node{
  public:
  int data, height;
  Node *left, *right;

  Node(int data){
    this->data = data, height = 1;
    left = right = NULL;
  }
};

int getHeight(Node* root){
  if(root == NULL)
    return 0;

  return root->height;
}

int getBalance(Node* root){
  return getHeight(root->left) - getHeight(root->right);
}

Node* leftRotate(Node* root){
  Node* child = root->right;
  Node* childLeft  = child->left;
  child->left = root;
  root->right = childLeft;
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  child->height = 1 + max(getHeight(child->left), getHeight(child->right));

  return child;
}

Node* rightRotate(Node* root){
  Node* child = root->left;
  Node* childRight = child->right;
  child->right = root;
  root->left = childRight;
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  child->height = 1 + max(getHeight(child->left), getHeight(child->right));

  return child;
}

Node* insert(Node* root, int data){
  if(root == NULL)
    return new Node(data);

  if(data < root->data)
    root->left = insert(root->left, data);
  else if(data > root->data)
    root->right = insert(root->right, data);
  else
    return root; //duplicates are not allowed

  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  int balanceFactor = getBalance(root);

  if(balanceFactor > 1 && data < root->left->data){
    //LL
    return rightRotate(root);
  }
  else if(balanceFactor < -1 && data > root->right->data){
    //RR
    return leftRotate(root);
  }
  else if(balanceFactor > 1 && data > root->left->data){
    //LR
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  else if(balanceFactor < -1 && data < root->right->data){
    //RL
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  
  return root;
}

Node* deleteFromAVL(Node* root, int data){
  if(root == NULL)
    return NULL;

  if(data < root->data)
    root->left = deleteFromAVL(root->left, data);
  else if(data > root->data)
    root->right = deleteFromAVL(root->right, data);
  else{
    if(root->left == NULL && root->right == NULL){
      delete root;
      return NULL;
    }
    else if(root->left != NULL && root->right == NULL){
      Node* temp = root->left;
      delete root;
      return temp;
    }
    else if(root->left ==  NULL && root->right != NULL){
      Node* temp = root->right;
      delete root;
      return temp;
    }
    else{
      Node* curr = root->right;
      while(curr->left)
        curr = curr->left;
      root->data = curr->data;
      root->right = deleteFromAVL(root->right, curr->data);
    }
  }

  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  int balanceFactor = getBalance(root);

  //Left
  if(balanceFactor > 1){
    if(getBalance(root->left) >= 0){
      //LL
      return rightRotate(root);
    }else{
      //LR
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  //Right
  else if(balanceFactor < -1){
    if(getBalance(root->right) <= 0){
      //RR
      return leftRotate(root);
    }else{
      //RL
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }

  return root;
}

void inorder(Node* root){
  if(root == NULL)
    return;

  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

pair<int,bool> isBalanced(Node* n){
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

int main() {
  Node* root = NULL;
  // root = insert(root, 10);
  // root = insert(root, 40);
  // root = insert(root, 30);
  // root = insert(root, 15);
  // root = insert(root, 60);
  // root = insert(root, 80);
  // root = insert(root, 90);
  // root = insert(root, 100);

  root = insert(root, 32);
  root = insert(root, 20);
  root = insert(root, 43);
  root = insert(root, 12);
  root = insert(root, 31);
  root = insert(root, 37);
  root = insert(root, 69);
  root = insert(root, 4);
  root = insert(root, 22);
  root = insert(root, 33);
  root = insert(root, 59);
  root = insert(root, 87);
  inorder(root);
  cout<<endl;

  root = deleteFromAVL(root, 31);
  root = deleteFromAVL(root, 59);
  root = deleteFromAVL(root, 4);
  root = deleteFromAVL(root, 32);
  root = deleteFromAVL(root, 22);
  root = deleteFromAVL(root, 43);
  root = deleteFromAVL(root, 20);
  root = deleteFromAVL(root, 69);
  inorder(root);
  cout<<endl;
  cout<<isBalanced(root).second<<endl;

  // root = deleteFromAVL(root, 10);
  // inorder(root);
  // cout<<endl;
  // root = deleteFromAVL(root, 60);
  // inorder(root);
  // cout<<endl;


  return 0;
}
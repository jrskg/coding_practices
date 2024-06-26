#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data, height;
  struct Node *left, *right;
};

typedef struct Node Node;

int getHeight(Node* root){
  if(root == NULL)
    return 0;

  return root->height;
}

int max(int a, int b){
  return a > b ? a : b; 
}

int getBalance(Node* root){
  return getHeight(root->left) - getHeight(root->right);
}

Node* leftRotate(Node* root){
  Node* right = root->right;
  Node* leftChild = right->right;
  right->left = root;
  root->right = leftChild;
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  right->height = 1 + max(getHeight(right->left), getHeight(right->right));

  return right;
}

Node* rightRotate(Node* root){
  Node* left = root->left;
  Node* rightChild = left->right;
  left->right = root;
  root->left = rightChild;
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  left->height = 1 + max(getHeight(left->left), getHeight(left->right));

  return left;
}

Node* insertIntoAVL(Node* root, int data){
  if(root == NULL){
    root = (Node*)malloc(sizeof(Node));
    root->data = data;
    root->height = 1;
    root->left = NULL;
    root->right = NULL;
    return root;
  }

  if(data < root->data){
    root->left = insertIntoAVL(root->left, data);
  }else if(data > root->data){
    root->right = insertIntoAVL(root->right, data);
  }else{
    return root;
  }

  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  int bf = getBalance(root);

  if(bf > 1 && data < root->left->data){
    //LL
    return rightRotate(root);
  }
  else if(bf < -1 && data > root->right->data){
    // RR
    return leftRotate(root);
  }
  else if(bf > 1 && data > root->left->data){
    //LR
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  else if(bf < -1 && data < root->right->data){
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
    if(!root->left && !root->right){
      free(root);
      return NULL;
    }
    else if(root->left && !root->right){
      Node* temp = root->left;
      free(root);
      return temp;
    }
    else if(!root->left && root->right){
      Node* temp = root->right;
      free(root);
      return temp;
    }
    else{
      Node* temp = root->right;
      while(temp->left != NULL)
        temp = temp->left;

      root->data = temp->data;
      deleteFromAVL(root->right, temp->data);
    }
  }
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  int bf = getBalance(root);

  //left
  if(bf > 1){
    if(getBalance(root->left) >= 0){
      //LL
      return rightRotate(root);
    }else{
      //LR
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }else if(bf < -1){
    //Right
    if(getBalance(root->right) <= 0){
      //RR
      return leftRotate(root);
    }else{
      // RL
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }

  return root;
}

int main() {
  
  return 0;
}
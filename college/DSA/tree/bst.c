#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

typedef struct Node Node;

Node* insertIntoBST(Node* root, int data){
  if(root == NULL){
    root = (Node*)malloc(sizeof(Node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
  }

  if(data < root->data){
    root->left = insertIntoBST(root->left, data);
  }else if(data > root->data){
    root->right = insertIntoBST(root->right, data);
  }

  return root;
}

Node* deleteFromBST(Node* root, int data){
  if(root == NULL)
    return NULL;

  if(data < root->data){
    root->left = deleteFromBST(root->left, data);
  }else if(data > root->data){
    root->right = deleteFromBST(root->right, data);
  }else{
    if(!root->left && !root->right){
      free(root);
      return NULL;
    }else if(root->left && !root->right){
      Node* temp = root->left;
      free(root);
      return temp;
    }else if(!root->left && root->right){
      Node* temp = root->right;
      free(root);
      return temp;
    }else{
      Node* temp = root->right;
      while(temp->left != NULL)
        temp = temp->left;

      root->data = temp->data;
      deleteFromBST(root->right, temp->data);
    }
  }
  return root;
}

int search(Node* root, int data){
  if(root == NULL)
    return 0;

  if(root->data == data)
    return 1;
  else if(data < root->data)
    return search(root->left, data);
  return search(root->right, data);
}

void inorder(Node* root){
  if(root == NULL)
    return;

  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

int main() {
  Node* root = NULL;
  root = insertIntoBST(root, 10);
  root = insertIntoBST(root, 5);
  root = insertIntoBST(root, 15);
  root = insertIntoBST(root, 12);
  root = insertIntoBST(root, 20);
  root = insertIntoBST(root, 18);
  root = insertIntoBST(root, 21);

  // root = deleteFromBST(root, 12);
  printf("%d\n", search(root, 9));

  inorder(root);
  return 0;
}
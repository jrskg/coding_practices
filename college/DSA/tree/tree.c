#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

typedef struct Node Node;

Node* createTree(Node* root){
  int n;
  printf("Enter data : ");
  scanf("%d", &n);

  if(n == -1)
    return NULL;

  root = (Node*)malloc(sizeof(Node));
  root->data = n;
  printf("Left of %d\n", n);
  root->left = createTree(root->left);
  printf("Right of %d\n", n);
  root->right = createTree(root->right);

  return root;
}

void inorder(Node* root){
  if(root == NULL)
    return;

  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void preorder(Node* root){
  if(root == NULL)
    return;

  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node* root){
  if(root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

int main() {
  Node* root = NULL;
  root = createTree(root);
  inorder(root);
  printf("\n");
  preorder(root);
  printf("\n");
  postorder(root);
  printf("\n");
  return 0;
}
#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node* bottom;

  Node(int data){
    this->data = data;
    this->next = NULL;
    this->bottom = NULL;
  }
};

Node* merge(Node* h1, Node* h2){
  Node* head = new Node(0);
  Node* tail = head;

  while(h1 && h2){
    if(h1->data < h2->data){
      tail->bottom = h1;
      h1 = h1->bottom;
    }else{
      tail->bottom = h2;
      h2 = h2->bottom;
    }
    tail = tail->bottom;
  }

  if(h1) tail->bottom = h1;
  if(h2) tail->bottom = h2;

  tail = head;
  head = head->bottom;
  delete tail;
  return head;
}

Node* flatten(Node* root){
  Node *h1, *h2, *h3;

  while(root->next){
    h1 = root;
    h2 = root->next;
    h3 = root->next->next;
    h1->next = NULL;
    h2->next = NULL;
    root = merge(h1, h2);
    root->next = h3;
  }
  return root;
}

int main() {
  
  return 0;
}
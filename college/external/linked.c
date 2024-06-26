#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

typedef struct Node Node;

Node* insert(Node* head, int data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;

  if(head == NULL){
    newNode->next = NULL;
    return newNode;
  }

  newNode->next = head;
  head = newNode;
  return head;
}

void traverse(Node* head){
  Node* temp = head;

  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  Node* head = NULL;
  head = insert(head, 10);
  head = insert(head, 20);
  head = insert(head, 30);
  head = insert(head, 40);

  traverse(head);
  
  return 0;
}
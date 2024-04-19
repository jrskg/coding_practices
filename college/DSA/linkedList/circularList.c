#include <stdio.h>
#include <stdlib.h>

struct circularList{
  int data;
  struct circularList* next;
};
typedef struct circularList Node;

void printList(Node* head){
  if(head == NULL){
    printf("List is empty\n");
    return;
  }
  Node* temp = head;
  while(temp->next != head){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("%d \n", temp->data);
}

Node* insertFirst(Node* head, int data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;

  if(head == NULL){
    head = newNode;
    head->next = head;
    return head;
  }

  Node* temp = head->next;
  while(temp->next != head){
    temp = temp->next;
  }

  newNode->next = head;
  head = newNode;
  temp->next = head;
  return head;
}

Node* insertLast(Node* head, int data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;

  if(head == NULL){
    head = newNode;
    head->next = head;
    return head;
  }

  Node* temp = head->next;
  while(temp->next != head){
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->next = head;
  return head;
}

int main() {
  Node* head = NULL;
  head = insertFirst(head, 10);
  head = insertFirst(head, 20);
  head = insertFirst(head, 30);
  head = insertLast(head, 90);
  head = insertLast(head, 100);
  printList(head);
  
  return 0;
}
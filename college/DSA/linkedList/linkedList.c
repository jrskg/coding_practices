#include <stdio.h>
#include <stdlib.h>

struct linkedList{
    int data;
    struct linkedList * next;
};
typedef struct linkedList Node;

void printList(Node* head){
    if(head == NULL){
        printf("Linked list is empty\n");
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }printf("\n");
}

Node* insertFirst(Node* head, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node* temp = head;
    head = newNode;
    newNode->next = temp;
}

Node* insertLast(Node* head, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return head;
    }

    Node* temp = head;
    while(temp != NULL && temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node insertAtPosition(Node* head, int data, int position){
    
}

int main() {
    Node* head = NULL;
    head = insertLast(head, 10);
    head = insertFirst(head, 90);
    head = insertLast(head, 20);
    head = insertFirst(head, 60);
    head = insertFirst(head, 40);
    printList(head);
    
    return 0;
}
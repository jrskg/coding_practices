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
    return head;
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

Node* insertAtPosition(Node* head, int data, int position){
    if(head == NULL){
        head = insertFirst(head, data);
        return head;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    Node* temp = head;

    for(int i = 1; i < position-1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Invalid position\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* deleteFirst(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteLast(Node* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

Node* deleteAtPosition(Node* head, int position){
    if(head == NULL){
        return NULL;
    }
    if(position == 1){
        return deleteFirst(head);
    }
    Node* temp = head;
    for(int i = 1; i < position-1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL){
        printf("Invalid position\n");
        return head;
    }
    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    return head;
}

int main() {
    Node* head = NULL;
    head = insertFirst(head, 10);
    printList(head);
    head = insertFirst(head, 30);
    printList(head);
    return 0;
}
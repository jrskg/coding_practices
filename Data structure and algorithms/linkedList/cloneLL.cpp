#include <iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* random;

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->random = NULL;
        }
};

void printList(Node* &head){
    Node* temp = head;
    if(temp == NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }
    while (temp != NULL){
        cout<<temp->data<<" ";
        if(temp->random != NULL){
            cout<<temp->random->data;
        }
        cout<<endl;

        temp = temp->next;
    }
    
}

void insertLast(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}
Node* clone(Node* head){
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* orgNode = head;

    //cloning without random
    while(orgNode != NULL){
        insertLast(cloneHead, cloneTail, orgNode->data);
        orgNode = orgNode->next;
    }
    unordered_map<Node*, Node*>oddToNewMap;

    orgNode = head;
    Node* cloneTemp = cloneHead;
    //mapping process
    while(orgNode != NULL){
        oddToNewMap[orgNode] = cloneTemp;
        orgNode = orgNode->next;
        cloneTemp = cloneTemp->next;
    }

    orgNode = head;
    cloneTemp = cloneHead;
    //setting random with the help of mapping
    while(orgNode != NULL){
        cloneTemp->random = oddToNewMap[orgNode->random];
        orgNode = orgNode->next;
        cloneTemp = cloneTemp->next;
    }
    return cloneHead;
}

Node* clone1(Node* head){
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* orgNode = head;

    while(orgNode != NULL){
        insertLast(cloneHead, cloneTail, orgNode->data);
        orgNode = orgNode->next;
    }

    orgNode = head;
    Node* cloneNode = cloneHead;
    Node* next = NULL;
    while(orgNode != NULL && cloneNode != NULL){
        next = orgNode->next;
        orgNode->next = cloneNode;
        orgNode = next;

        next = cloneNode->next;
        cloneNode->next = orgNode;
        cloneNode = next;
    }

    orgNode = head;
    while(orgNode != NULL){
        if(orgNode->next != NULL){
            //checking if orgNode->random != NULL
            orgNode->next->random = orgNode->random ? orgNode->random->next : orgNode->random;
        }
        orgNode = orgNode->next->next;
    }

    orgNode = head;
    cloneNode = cloneHead;
    while(orgNode != NULL && cloneNode != NULL){
        orgNode->next = cloneNode->next;
        orgNode = orgNode->next;
        if(orgNode != NULL){
            cloneNode->next = orgNode->next;
        }
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}
int main() {

    Node* head = new Node(1);
    Node* tail = head;
    insertLast(head, tail, 2);
    insertLast(head, tail, 3);
    insertLast(head, tail, 4);
    insertLast(head, tail, 5);
    tail->random = head->next;
    tail->random->next->random = head->next->next;
    printList(head);

    // Node* cloned = clone(head);
    Node* cloned = clone1(head);
    printList(cloned);    
    return 0;
}
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
// TODO create another function to clone with SC O(1)
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

    Node* cloned = clone(head);

    printList(cloned);
    
    return 0;
}
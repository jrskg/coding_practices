#include <iostream>
#include <map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printList(Node* &tail){
    Node* temp = tail;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail);
    cout<<endl;
}

void insertNode(Node* &tail, int data){
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }else{
        Node* temp = tail;
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
        tail = newNode;
    }
}


bool isCircular(Node* head){
    if(head == NULL){
        return true;
    }

    Node* temp = head->next;

    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    if(temp == NULL){
        return false;
    }
    // if(temp == head){
    //     return true;
    // }
    return true;
}

map<int, Node*> divideList(Node* head){
    map<int, Node*>ans;
    if(head == head->next){
        return ans;
    }

    Node* fast = head->next;
    Node* slow = head;

    while(fast->next != head){
        fast = fast->next;
        if(fast->next != head){
            fast = fast->next;
            slow = slow->next; 
        }
    }
    Node* secondHead = slow->next;
    fast->next = secondHead;
    slow->next = head;
    ans[1] = head;
    ans[2] = secondHead;
    return ans;
}

//TODO:create a function to delete a node from circular linked list

int main() {
    Node* tail = NULL;
    insertNode(tail, 1);
    insertNode(tail, 2);
    insertNode(tail, 3);
    insertNode(tail, 4);
    // insertNode(tail, 5);
    // insertNode(tail, 6);
    printList(tail);
    // cout<<isCircular(tail)<<endl;
    map<int, Node*>ans = divideList(tail);
    printList(ans[1]);
    printList(ans[2]);
    
    return 0;
}
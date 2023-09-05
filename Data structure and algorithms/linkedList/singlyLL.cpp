#include <iostream>
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

void printList(Node* &head){
    Node* temp = head;
    while (temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtFirst(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtLast(Node* &tail, int data){
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    int length = 0;
    Node* temp = head;

    while(temp != NULL){
        length++;
        temp = temp->next;
    }

    if(position < 1 || position > length+1){
        cout<<"Invalid position (position = "<<position<<") can't insert!!"<<endl;
        return;
    }

    if(position == 1){
        insertAtFirst(head, data);
    }else if(position == length + 1){
        insertAtLast(tail, data);
    }else{
        temp = head;
        for(int i = 1; i < position-1; i++){
            temp = temp->next;
        }   
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFirst(Node* &head){
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void deletePosition(Node* &head, Node* &tail, int position){
    int length = 0;
    Node* curr = head;
    while(curr != NULL){
        length++;
        curr = curr->next;
    }

    if(position < 1 || position > length){
        cout<<"Invalid position (position = "<<position<<") can't delete!!"<<endl;
        return;
    }

    if(position == 1){
        curr = head;
        head = head->next;
        curr->next = NULL;
        delete curr;
    }else{
        Node* prev = NULL;
        curr = head;
        for(int i = 1; i < position; i++){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        if(position == length){
            tail = prev;
        }
        delete curr;
    }
}

void deleteElementPos(Node* &head, Node* &tail, int element){
    int pos = 0;
    bool isFound = false;
    Node* temp = head;
    while(temp != NULL){
        pos++;
        if(element == temp->data){
            isFound = true;
            break;
        }
        temp = temp->next;
    }
    if(isFound){
        deletePosition(head, tail, pos);
    }else{
        cout<<"The given element ("<<element<<") do not exist!!"<<endl;
    }
}

void deleteElement(Node* &head, Node* &tail, int element){
    int pos = 0;
    bool isFound = false;
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        if(curr->data == element){
            isFound = true;
            if(prev == NULL){
                //here prev == null means the element is in the head so update head
                head = curr->next;
            }else{
                //here prev != null means the element is not in the head and can be anywhere except head so update normally
                prev->next = curr->next;
            }
            if(curr == tail){
                //if curr == tail means the element is in tail node so update tail
                tail = prev;
            }
            curr->next = NULL;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    if(!isFound){
        cout<<"The given element ("<<element<<") do not exist!!"<<endl;
    }
}

int main() {

    Node* node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;

    for(int i = 0; i < 5; i++){
        insertAtLast(tail,i+6);
    }
    // printList(head);
    // insertAtPosition(head, tail, 11, 0);
    // insertAtPosition(head, tail, 11, 1);
    // insertAtPosition(head, tail, 11, 9);

    // printList(head);
    // deletePosition(head, tail, 0);
    // deletePosition(head, tail, 1);
    // deletePosition(head, tail, 6);
    // printList(head);


    printList(head);
    deleteElement(head, tail, 7);
    deleteElement(head, tail, 5);
    printList(head);

    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;

    return 0;
}
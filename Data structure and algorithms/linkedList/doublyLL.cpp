#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
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
void printListTail(Node* &tail){
    Node* temp = tail;
    while (temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}
int getLength(Node* &head){
    Node* temp = head;
    int len = 0;
    while (temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void insertFirst(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }else{
        Node* newNode = new Node(data);
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}
void insertLast(Node* &head, Node* &tail, int data){
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
    }else{
        Node* newNode = new Node(data);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}
void insertPosition(Node* &head, Node* &tail, int data, int position){
    if(position == 1){
        insertFirst(head, tail, data);
        return;
    }
    int len = getLength(head);
    if(position < 1 || position > len+1){
        cout<<"Invalid position ("<<position<<") can't insert"<<endl;
        return;
    }
    if(position == len+1){
        insertLast(head, tail, data);
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;
    for(int i = 1; i < position-1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deletePosition(Node* &head, Node* &tail, int position){
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int len = getLength(head);
    if(position < 0 || position > len){
        cout<<"Invalid position ("<<position<<") can't delete!!"<<endl;
        return;
    }
    Node* curr = head;
    for(int i = 1; i < position; i++){
        curr = curr->next;
    }
    curr->prev->next = curr->next;
    if(curr->next != NULL){
        //if its not the last position then updating the current->next->previous
        curr->next->prev = curr->prev;
    }else{
        //if its the last then updating tail to current->prevoius
        tail = curr->prev;
    }
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}
void deleteElement(Node* &head, Node* &tail, int element){
    bool isFound = false;
    Node* curr = head;
    while(curr != NULL){
        if(curr->data == element){
            isFound = true;
            if(curr->prev == NULL){
                //if its true means th element is in head node so handle head
                curr->next->prev = NULL;
                head = curr->next;
            }else{
                //its not head it can be either middle or tail
                curr->prev->next = curr->next;
                if(curr->next != NULL){
                    //means its not tail so do not update tail
                    curr->next->prev = curr->prev;
                }else{
                    //means its tail so update tail as well
                    tail = curr->prev;
                }
            }
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
            break;
        }
        curr = curr->next;
    }
    if(!isFound){
        cout<<"The element ("<<element<<") do not exist can't delete!!"<<endl;
    }
}

void removeDuplicateDoubly(Node* head){
    if(head == NULL){
        return;
    }
    Node* curr = head;
    Node* duplicate = NULL;
    while(curr != NULL && curr->next != NULL){
        if(curr->data == curr->next->data){
            duplicate = curr->next;
            curr->next = duplicate->next;
            if(duplicate->next != NULL){
                duplicate->next->prev = curr;
            }
            duplicate->next = NULL;
            duplicate->prev = NULL;
            delete duplicate;
        }else{
            curr = curr->next;
        }
    }
}


int main() {
    Node * node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;
    for(int i = 0; i < 5; i++){
        insertLast(head, tail, i+6);
    }
    // printList(head);
    // insertPosition(head, tail, 0, 1);
    // insertPosition(head, tail, 100, 8);
    // printList(head);
    // printListTail(tail);

    printList(head);
    // deletePosition(head, tail, 6);
    deleteElement(head, tail, 5);
    deleteElement(head, tail, 7);
    deleteElement(head, tail, 10);
    printList(head);
    printListTail(tail);

    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;
    return 0;
}
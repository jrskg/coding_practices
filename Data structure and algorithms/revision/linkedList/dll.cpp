#include <iostream>
#include <vector>
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

void printList(Node* head){
  Node* temp = head;
  while(temp){
    cout<<temp->data<<" ";
    temp = temp->next;
  }cout<<endl;
}

Node* insertFirst(Node* head, int data){
  Node* newNode = new Node(data);
  if(!head) return newNode;

  newNode->next = head;
  head->prev = newNode;
  head = newNode;
  return head;
}

Node* insertLast(Node* head, int data){
  Node* newNode = new Node(data);
  if(!head) return newNode;

  Node* temp = head;
  while(temp->next) temp = temp->next;
  temp->next = newNode;
  newNode->prev = temp;
  return head;
}

Node* createDLL(vector<int> &arr){
  int size = arr.size();
  Node* temp = NULL;
  for(int i = size-1; i >= 0; i--){
    temp = insertFirst(temp, arr[i]);
  }

  return temp;
}

Node* createDLLRec(vector<int> &arr, int i){
  if(i >= arr.size()) return NULL;
  Node* temp = createDLLRec(arr, i+1);
  Node* newNode = new Node(arr[i]);
  newNode->next = temp;
  if(temp) temp->prev = newNode;
  return newNode;
}

Node* insertAtPos(Node* head, int data, int p){
  if(p <= 0) return insertFirst(head, data);
  Node* temp = head;
  int count = 0;
  while(temp){
    count++;
    temp = temp->next;
  }

  if(p >= count) return insertLast(head, data);
  temp = head;
  while(--p) temp = temp->next;
  Node* newNode = new Node(data);
  newNode->next = temp->next;
  newNode->next->prev = newNode;
  temp->next = newNode;
  newNode->prev = temp;

  return head;
}

Node* deleteFirst(Node* head){
  if(!head) return NULL;
  if(!head->next){
    delete head;
    return NULL;
  }

  Node* temp = head;
  head = head->next;
  head->prev = NULL;
  delete temp;

  return head;
}

Node* deleteLast(Node* head){
  if(!head) return NULL;
  if(!head->next){
    delete head;
    return NULL;
  }

  Node* temp = head;
  while(temp->next) temp = temp->next;
  temp->prev->next = NULL;
  temp->prev = NULL;
  delete temp;
  return head;
}

Node* deleteAtPos(Node* head, int p){
  if(!head) return NULL;
  if(p <= 1) return deleteFirst(head);

  int count = 0;
  Node* temp = head;
  while(temp){
    count++;
    temp = temp->next;
  }

  if(p >= count) return deleteLast(head);
  temp = head;
  while(--p) temp = temp->next;
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  delete temp;
  return head;
}

int main() {
  Node* head = NULL;
  // head = insertFirst(head, 10);
  // head = insertFirst(head, 20);
  // head = insertFirst(head, 30);
  // head = insertFirst(head, 40);

  // head = insertLast(head, 10);
  // head = insertLast(head, 20);
  // head = insertLast(head, 30);
  // head = insertLast(head, 40);
  // head = insertLast(head, 50);

  vector<int> arr = {1, 2, 3, 4, 5};
  // head = createDLL(arr);
  head = createDLLRec(arr, 0);
  // head = insertAtPos(head, 20, 3);

  // head = deleteFirst(head);
  // head = deleteLast(head);
  head = deleteAtPos(head, 2);

  printList(head);
  return 0;
}
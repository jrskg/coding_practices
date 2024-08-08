#include <iostream>
#include <unordered_map>
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

Node* cloneOne(Node* head){
  Node *copy, *tail, *temp, *r = NULL;
  copy = new Node(0);
  tail = copy;
  temp = head;

  while(temp){
    tail->next = new Node(temp->data);
    tail = tail->next;
    temp = temp->next;
  }

  tail = copy;
  copy = copy->next;
  delete tail;
  unordered_map<Node*, Node*> map;
  tail = copy;
  temp = head;

  while(temp){
    map[temp] = tail;
    temp = temp->next;
    tail = tail->next;
  }

  tail = copy;
  temp = head;

  while(temp){
    r = temp->random;
    tail->random = map[r];
    tail = tail->next;
    temp = temp->next;
  }
  return copy;
}

Node* cloneTwo(Node* head){
  Node *copy, *tail, *temp;
  copy = new Node(0);
  tail = copy;
  temp = head;
  while(temp){
    tail->next = new Node(temp->data);
    tail = tail->next;
    temp = temp->next;
  }
  tail = copy;
  copy = copy->next;
  delete tail;

  Node *front1, *front2;
  temp = head;
  tail = copy;
  while(temp){
    front1 = temp->next;
    front2 = tail->next;
    temp->next = tail;
    tail->next = front1;
    temp = front1;
    tail = front2;
  }

  front1 = head;
  front2 = head->next;
  while(front1){
    if(front1->random) front2->random = front1->random->next;
    front1 = front2->next;
    front2 = front2->next;
    if(front2) front2 = front2->next;
  }

  copy = head->next;
  tail = copy;
  temp = head;
  while(temp){
    temp->next = tail->next;
    if(temp->next) tail->next = temp->next->next;
    temp = temp->next;
    tail = tail->next;
  }
  return copy;
}

int main() {
  
  return 0;
}
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

class Queue{
  Node *qFront, *rear;
  int total;
  public:
  Queue(){
    qFront = rear = NULL;
    total = 0;
  }
  bool empty(){
    return qFront == NULL;
  }
  void push(int data){
    Node* temp = new Node(data);
    total++;
    if(empty()){
      qFront = rear = temp;
      return;
    }
    rear->next = temp;
    rear = rear->next;
  }
  void pop(){
    if(empty()) return;
    total--;
    if(qFront == rear){
      delete qFront;
      qFront = rear = NULL;
      return;
    }
    Node *temp = qFront;
    qFront = qFront->next;
    delete temp;
  }
  int front(){
    if(empty()) return -1;
    return qFront->data;
  }
  int size(){
    return total;
  }
};

int main() {
  Queue q;
  q.push(10);
  cout<<q.front()<<endl;
  q.pop();
  cout<<q.size()<<endl;
  return 0;
}
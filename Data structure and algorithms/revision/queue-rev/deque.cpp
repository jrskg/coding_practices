#include <iostream>
#include <deque>
using namespace std;

class Node{
  public:
  int data;
  Node* prev, *next;
  Node(int data){
    this->data = data;
    prev = NULL;
    next = NULL;
  }
};

class Deque{
  Node *qFront, *rear;
  int total;
  public:
  Deque(){
    this->qFront = NULL;
    this->rear = NULL;
    this->total = 0;
  }

  void push_front(int data){
    Node* temp = new Node(data);
    total++;
    if(empty()){
      qFront = rear = temp;
      return;
    }
    temp->next = qFront;
    qFront->prev = temp;
    qFront = temp;
  }
  void push_back(int data){
    Node* temp = new Node(data);
    total++;
    if(empty()){
      qFront = rear = temp;
      return;
    }
    rear->next = temp;
    temp->prev = rear;
    rear = temp;
  }
  int pop_front(){
    if(empty()) return -1;
    total--;
    Node* temp = qFront;
    qFront = qFront->next;
    int data = temp->data;
    if(!qFront) qFront = rear = NULL;
    else qFront->prev = NULL;
    delete temp;
    return data;
  }
  int pop_back(){
    if(empty()) return -1;
    total--;
    Node* temp = rear;
    rear = rear->prev;
    if(rear) rear->next = NULL;
    else qFront = rear = NULL;
    temp->prev = NULL;
    int data = temp->data;
    delete temp;
    return data;
  }
  int front(){
    if(empty()) return -1;
    return qFront->data;
  }
  int back(){
    if(empty()) return -1;
    return rear->data;
  }
  int size(){
    return total;
  }
  bool empty(){
    return qFront == NULL;
  }
};

class Deque2{
  int *arr;
  int capacity, qFront, rear, count;
  public:
  Deque2(int capacity){
    this->capacity = capacity;
    qFront = rear = -1;
    this->arr = new int[capacity];
    count = 0;
  }
  bool empty(){
    return qFront == -1;
  }
  bool full(){
    return (rear+1)%capacity == qFront;
  }
  void push_front(int data){
    if(full()) return;
    count++;
    if(empty()){
      qFront = rear = 0;
      arr[0] = data;
      return;
    }
    qFront = (qFront-1+capacity) % capacity;
    arr[qFront] = data;
  }
  void push_back(int data){
    if(full()) return;
    count++;
    if(empty()){
      qFront = rear = 0;
      arr[0] = data;
      return;
    }
    rear = (rear+1)%capacity;
    arr[rear] = data;
  }
  int pop_front(){
    if(empty()) return -1;
    count--;
    int data = arr[qFront];
    qFront = (qFront+1)%capacity;
    if(full()) qFront = rear = -1;
    return data;
  }
  int pop_back(){
    if(empty()) return -1;
    count--;
    int data = arr[rear];
    rear = (rear-1+capacity)%capacity;
    if(full()) qFront = rear = -1;
    return data;
  }
  int back(){
    if(empty()) return -1;
    return arr[rear];
  }
  int front(){
    if(empty()) return -1;
    return arr[qFront];
  }
  int size(){
    return count;
  }
};

int main() {
  Deque2 d(5);
  d.push_front(1);
  d.push_front(2);
  d.push_front(3);
  d.push_back(10);
  d.pop_front();d.pop_front(); d.pop_back();
  cout<<d.front()<<endl;
  cout<<d.back()<<endl;
  cout<<d.size()<<endl;

  // cout<<d.pop_back()<<endl;
  // cout<<d.pop_front()<<endl;

  return 0;
}
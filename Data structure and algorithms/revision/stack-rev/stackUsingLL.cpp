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

class Stack{
  int sSize;
  Node* top;

  public:
  Stack(){
    this->sSize = 0;
    this->top = NULL;
  }

  void push(int data){
    Node* temp = new Node(data);
    temp->next = top;
    top = temp;
    sSize++;
  }

  void pop(){
    if(top == NULL){
      cout<<"Stack Underflow"<<endl;
      return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
    sSize--;
  }

  int peek(){
    if(top == NULL){
      cout<<"Stack Underflow"<<endl;
      return -1;
    }
    return top->data;
  }

  int size(){
    return sSize;
  }

  bool isEmpty(){
    return top == NULL;
  }
};

int main() {
  
  return 0;
}
#include <iostream>
using namespace std;

class Stack{
  int capacity;
  int top;
  int* arr;

  public:
  Stack(int size){
    capacity = size;
    top = -1;
    arr = new int[size];
  }

  void push(int data){
    if(top == capacity-1){
      cout<<"Stack Overflow"<<endl;
      return;
    }

    top++;
    arr[top] = data;
  }

  void pop(){
    if(top == -1){
      cout<<"Stack Underflow"<<endl;
      return;
    }
    top--;
  }

  int peek(){
    if(top == -1){
      cout<<"Stack Underflow"<<endl;
      return -1;
    }
    return arr[top];
  }

  int size(){
    return top+1;
  }

  bool isEmpty(){
    return top == -1;
  }

  bool isFull(){
    return top == capacity-1;
  }
};

int main() {
  Stack s(10);
  return 0;
}
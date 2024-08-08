#include <iostream>
#include <stack>
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

class NStack{
  //when you want to store data in the array 
  int* arr;
  stack<int> spaces;
  Node** tops;

  public:
  NStack(int arrSize, int stackCount){
    this->arr = new int[arrSize];
    this->tops = new Node*[stackCount];
    for(int i = 0; i < stackCount; i++)
      tops[i] = NULL;
    for(int i = 0; i < arrSize; i++)
      spaces.push(i);
  }
  bool push(int data, int stackNumber){
    if(spaces.empty()) return false;
    arr[spaces.top()] = data;
    Node* temp = new Node(spaces.top());
    temp->next = tops[stackNumber-1];
    tops[stackNumber-1] = temp;
    spaces.pop();
    return true;
  }
  int pop(int stackNumber){
    if(!tops[stackNumber-1]) return -1;
    Node* temp = tops[stackNumber-1];
    int data = arr[temp->data];
    tops[stackNumber-1] = temp->next;
    delete temp;
    return data;
  }
};

class NStack2{
  //using linked list only to directly store the data (optimized)
  Node **list;
  int capacity;
  public:
  NStack2(int capacity, int stackCount){
    this->capacity = capacity;
    this->list = new Node*[stackCount];
    for(int i = 0; i < stackCount; i++)
      this->list[i] = NULL;
  }

  bool push(int data, int stackNumber){
    if(capacity <= 0) return false;
    capacity--;
    Node* temp = new Node(data);
    temp->next = list[stackNumber-1];
    list[stackNumber-1] = temp;
    return true;
  }
  int pop(int stackNumber){
    Node* temp = list[stackNumber-1];
    if(!temp) return -1;
    int data = temp->data;
    list[stackNumber-1] = temp->next;
    delete temp;
    capacity++;
    return data;
  }
};

int main() {
  NStack st(10, 3);
  st.push(300, 3);
  cout<<st.pop(1)<<endl;
  cout<<st.pop(3)<<endl;
  return 0;
}
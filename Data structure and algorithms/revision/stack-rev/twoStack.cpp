#include <iostream>
using namespace std;

class TwoStack{
  int top1, top2, size;
  int *arr;
  public:
  TwoStack(int size){
    this->size = size;
    top1 = -1;
    top2 = size;
    arr = new int[size];
  }

  void push1(int x){
    if(top1+1 == top2) return;
    top1++;
    arr[top1] = x;
  }
  int pop1(){
    if(top1 == -1) return -1;
    int elem = arr[top1];
    top1--;
    return elem;
  }
  void push2(int x){
    if(top2-1 == top1) return;
    top2--;
    arr[top2] = x;
  }
  int pop2(){
    if(top2 == size) return -1;
    int elem = arr[top2];
    top2++;
    return elem;
  }
};

int main() {
  TwoStack *st = new TwoStack(5);
  st->push1(10);
  st->push2(20);
  cout<<st->pop2()<<endl;
  cout<<st->pop1()<<endl;
  return 0;
}
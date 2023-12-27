#include <iostream>
using namespace std;

class TwoStack {
    int top1;
    int top2;
    int * arr;
    int size;

    public:
    TwoStack(int s) {
        this->size = s;
        arr = new int[s];
        top1 = -1;
        top2 = s;
    }
    void push1(int num) {
        if(top2-top1 > 1){
            top1++;
            arr[top1] = num;
        }
    }
    void push2(int num) {
        if(top2-top1 > 1){
            top2--;
            arr[top2] = num;
        }
    }
    int pop1() {
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }else{
            return -1;
        }
    }
    int pop2() {
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }else{
            return -1;
        }
    }
};


class Stack{
    int top;
    int size;
    int* arr;

    public:
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data){
        if(size - top > 1){
            top++;
            arr[top] = data;
        }else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop(){
        if(top >= 0){
            top--;
        }else{
            cout<<"Stack Underflow"<<endl;
        }
    }
    int peek(){
        if(top >= 0){
            return arr[top];
        }else{
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
    }
    bool empty(){
        return top == -1;
    }
};

int main() {
    Stack s1(4);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout<<s1.empty()<<endl;
    cout<<s1.peek()<<endl;
    
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

class Stack{
  stack<int> st;
  int minEle;

  public:
  void push(int x){
    if(st.empty()){
      minEle = x;
      st.push(x*101+minEle);
      return;
    }
    minEle = min(x, minEle);
    st.push(x*101+minEle);
  }

  int pop(){
    if(st.empty()) return -1;
    int toReturn = st.top()/101;
    st.pop();
    if(st.empty()) minEle = -1;
    else minEle = st.top()%101;
    return toReturn;
  }

  int getMin(){
    if(st.empty()) return -1;
    return minEle;
  }
};

int main() {
  Stack s;
  s.push(2);
  s.push(4);
  cout<<s.getMin()<<endl;
  return 0;
}
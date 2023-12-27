#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int>s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.pop();

    cout<<"The top element is : "<<s.top()<<endl;
    cout<<"Size of stack is : "<<s.size()<<endl;
    cout<<s.empty()<<endl;

    return 0;
}
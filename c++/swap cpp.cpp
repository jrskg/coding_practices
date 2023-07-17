#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
  a = a + b;
  b = a - b;
  a = a - b;
}

int main()
{
    int a, b;
    cout<<"Enter first number"<<endl;
    cin>>a;
    cout<<"Enter second number"<<endl;
    cin>>b;
    cout<<a<<" "<<b<<endl;
    swap(a, b); 
    cout<<a<<" "<<b;  
    return 0;
}
    
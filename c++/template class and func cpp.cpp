#include<iostream>
using namespace std;

template <class T = int, class T1 = char>
class myClass
{
public:
    T a;
    T1 b;
    myClass(T m, T1 n)
    {
        a = m;
        b = n;
    }
    void swapp()
    {
        a = a+b;
        b = a-b;
        a = a-b;
    }
    void display()
    {
        cout<<"The value of a is "<<a<<endl;
        cout<<"The value of b is "<<b<<endl;
    }
};

template<class T2, class T3>
float average(T2 a, T3 b)
{
    float avg = (a+b)/2.0;
    return avg;
}

int main()
{
    myClass<char, char>obj1('e', 'f');
    //obj1.display();
    //obj1.swapp();
    //obj1.display();
    float val = average(3.1, 6.9);
    cout<<val;

    return 0;
}
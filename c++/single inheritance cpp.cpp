#include <iostream>
using namespace std;

class Base
{
    int a, b;

public:
    void setdata()
    {
        a = 2;
        b = 3;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
};

class Derived : private Base
{
    int c;
public:
    void process()
    {
        setdata();
        c = getA() * getB();
    }
    void show()
    {
        cout<<"The value of a is "<<getA()<<endl;
        cout<<"The value of b is "<<getB()<<endl;
        cout<<"The value of c is "<<c<<endl;
    }
};

int main()
{
    Derived d;
    // d.setdata();
    d.process();
    d.show();

    return 0;
}

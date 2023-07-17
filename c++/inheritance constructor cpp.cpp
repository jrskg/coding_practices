#include<iostream>
using namespace std;

class Base1
{
    int data1;
public:
    Base1(int a)
    {
        data1 = a;
        cout<<"Base1 constructor called."<<endl;
    }
    void printBase1()
    {
        cout<<"The value of data1 is "<<data1<<endl;
    }
};

class Base2
{
    int data2;
public:
    Base2(int a)
    {
        data2 = a;
        cout<<"Base2 constructor called."<<endl;
    }
    void printBase2()
    {
        cout<<"The value of data2 is "<<data2<<endl;
    }
};

class Derived : public Base1, public Base2
{
    int derived1, derived2;
public:
    Derived(int a, int b, int c, int d):Base1(a), Base2(b)
    {
        derived1 = c;
        derived2 = d;
        cout<<"Derived constructor called."<<endl;
    }
    void printDerived()
    {
        cout<<"The value of derived1 is "<<derived1<<endl;
        cout<<"The value of derived2 is "<<derived2<<endl;
    }
};

int main()
{
    Derived suraj(1, 2, 3, 4);
    suraj.printBase1();
    suraj.printBase2();
    suraj.printDerived();
    return 0;
}
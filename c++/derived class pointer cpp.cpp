#include<iostream>
using namespace std;

class Base
{
public:
    int var_base;
    void display()
    {
        cout<<"The base class function is running "<<var_base<<endl;
    }
};

class Derived : public Base
{
public:
    int var_derived;
    void display()
    {
        cout<<"The derived class function is running "<<var_derived<<endl;
    }
};

int main()
{
    Base * base_pointer;
    Base obj_base;
    
    Derived*derived_pointer, obj_derived;
    derived_pointer = &obj_derived;
    base_pointer = &obj_derived;

    base_pointer->var_base = 23;
    base_pointer->display();

    derived_pointer->var_derived = 56;
    derived_pointer->display();

    return 0;
}
#include <iostream>
using namespace std;

class Y;

class X
{
    int val1;

    friend void swap(X &s, Y &m);

public:
    void set(int a)
    {
        val1 = a;
    }
    void display(void)
    {
        cout<<val1<<endl;
    }
};


class Y
{
    int val2;

    friend void swap(X &s, Y &m);

public:
    void set(int a)
    {
        val2 = a;
    }
    void display(void)
    {
        cout<<val2<<endl;
    }
};

void swap(X &s, Y &m)
{
    s.val1 = s.val1 + m.val2;
    m.val2 = s.val1 - m.val2;
    s.val1 = s.val1 - m.val2;
}

int main()
{
    X o1;
    o1.set(5);

    Y o2;
    o2.set(6);
    cout<<"The value of o1 before exchanging becomes:";
    o1.display();

    cout<<"The value of o2 before exchanging becomes:";
    o2.display();

    swap(o1, o2);
    cout<<"The value of o1 after exchanging becomes:";
    o1.display();

    cout<<"The value of o2 after exchanging becomes:";
    o2.display();


    return 0;
}

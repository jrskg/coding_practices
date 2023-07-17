#include<iostream>
using namespace std;

class student
{
protected:
    int roll;
public:
    void setRoll(int);
    void getRoll();
};

void student::setRoll(int n)
{
    roll = n;
}

void student::getRoll()
{
    cout<<"The roll no is "<<roll<<endl;
}

class exam : public student
{
protected:
    int physics;
    int maths;
public:
    void setMark(int, int);
    void getMark();
};

void exam :: setMark(int m, int n)
{
    physics = m;
    maths = n;
}

void exam :: getMark()
{
    cout<<"The mark in physics is "<<physics<<endl;
    cout<<"The mark in maths is "<<maths<<endl;
}

class result : public exam
{
public:
    void Display()
    {
        setRoll(420);
        setMark(88, 92);
        cout<<"The result of the student is "<<(physics+maths)/2<<endl;
    }
};

int main()
{
    result suraj;
    suraj.Display();
    suraj.getRoll();
    suraj.getMark();
    return 0;
}
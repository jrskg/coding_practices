#include<iostream>
using namespace std;

class student
{
protected:
    int roll;
public:
    void setRoll(int n)
    {
        roll = n;
    }
    void printRoll()
    {
        cout<<"Your roll no is:"<<roll<<endl;
    }
};

class test : virtual public student
{
protected:
    float physics, maths;
public:
    void setMarks(float m1, float m2)
    {
        physics = m1;
        maths = m2;
    }
    void printMarks()
    {
        cout<<"Your marks is:"<<endl
            <<"Physics:"<<physics<<endl
            <<"Maths:"<<maths<<endl;
    }
};

class sports : virtual public student
{
protected:
    float score;
public:
    void setScore(float sc)
    {
        score = sc;
    }
    void printScore()
    {
        cout<<"Your pt score is:"<<score<<endl;
    }
};

class result : public test, public sports
{
    float results;
public:
    void setResult()
    {
        results = maths + physics + score;
    }
    void display()
    {
        printRoll();
        printMarks();
        printScore();
        cout<<"You total result is:"<<results<<endl;
    }
};

int main()
{
    result suraj;
    suraj.setRoll(101);
    suraj.setMarks(95.5, 96.5);
    suraj.setScore(10);
    suraj.setResult();
    suraj.display();
    return 0;
}
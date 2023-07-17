#include<iostream>
using namespace std;

class CWH
{
protected:
    string title;
    float rating;
public:
    CWH(string tl, float r)
    {
        title = tl;
        rating = r;
    }
    //virtual void display() {}
    virtual void display() = 0;//pure virtual function
};

class CWHvideo : public CWH
{
    float videoLen;
public:
    CWHvideo(string tl, float r, float vl):CWH(tl, r)
    {
        videoLen = vl;
    }
    void display()
    {
        cout<<"This is video tutorial of "<<title<<endl;
        cout<<"Rating:"<<rating<<" out of 5 star"<<endl;
        cout<<"Length of the video is "<<videoLen<<" minutes"<<endl<<endl;;
    }
};

class CWHtext : public CWH
{
    int words;
public:
    CWHtext(string tl, float r, int wr):CWH(tl, r)
    {
        words = wr;
    }
    void display()
    {
        cout<<"This is text tutorial of "<<title<<endl;
        cout<<"Rating:"<<rating<<" out of 5 star"<<endl;
        cout<<"Number of words in the tutorial "<<words<<" words"<<endl;
    }
};

int main()
{
    string ti = "C++ language";
    float vr = 4.5;
    float tr = 4.4;
    float ln = 10.5;
    int wr = 500;

    CWH * ptr[2];

    CWHvideo M(ti, vr, ln);
    ptr[0] = &M;
    ptr[0]->display();

    CWHtext S(ti, tr, wr);
    ptr[1] = &S;
    ptr[1]->display();
    return 0;
}
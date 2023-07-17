#include <iostream>
#include <string>
using namespace std;

class binary
{
private:
    string s;
public:
    void read(void);
    void check(void);
    void change(void);
    void display(void);
};

void binary::read(void)
{
    cout<<"Enter your binary number"<<endl;
    cin>>s;
    check();
}

void binary::check(void)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s.at(i) != '0' && s.at(i) != '1')
        {
            cout<<"Incorrect binary format"<<endl;
            exit(0);
        }

    }
}

void binary::change(void)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s.at(i) == '0')
        {
            s.at(i) = '1';
        }
        else
        {
            s.at(i) = '0';
        }
    }
}

void binary::display(void)
{
    cout<<"Your binary number is "<<s<<endl;
}

int main()
{
    binary a;
    a.read();
    // a.check();
    a.display();
    a.change();
    a.display();
    return 0;
}

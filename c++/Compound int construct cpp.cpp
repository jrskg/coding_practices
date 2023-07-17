#include <iostream>
using namespace std;

class bankDeposit
{
    int principal, years;
    float intRate;
    float retValue;

public:
    bankDeposit() {}
    bankDeposit(int p, int y, float r);
    bankDeposit(int p, int y, int R);
    void show();

};

bankDeposit::bankDeposit(int p, int y, float r)
{
    principal = p;
    years = y;
    intRate = r;
    retValue = principal;

    for(int i = 0; i < years; i++)
    {
        retValue = retValue * (1+intRate);
    }

}

bankDeposit::bankDeposit(int p, int y, int R)
{
    principal = p;
    years = y;
    intRate = float(R)/100;
    retValue = principal;

    for(int i = 0; i < years; i++)
    {
        retValue = retValue * (1+intRate);
    }

}

void bankDeposit::show()
{
    cout<<"The principal amount is:"<<principal
        <<endl<<"The amount becomes:"<<retValue<<" after "<<years<<" years"<<endl<<endl;
}


int main()
{
    bankDeposit c1, c2, c3;
    int p, y, R;
    float r;
    cout<<"Enter the value of principal, years and rate r"<<endl;
    cin>>p>>y>>r;
    c1 = bankDeposit(p, y, r);
    c1.show();

    cout<<"Enter the value of principal, years and rate R"<<endl;
    cin>>p>>y>>R;
    c2 = bankDeposit(p, y, R);
    c2.show();


    return 0;
}

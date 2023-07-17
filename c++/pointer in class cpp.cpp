#include<iostream>
using namespace std;

class Shop
{
    int rekNum;
    float price;
    string name;
public:
    void setData(int a, float b, string c)
    {
        rekNum = a;
        price = b;
        name = c;
    }
    void getData(void)
    {
        cout<<"Name of the item is "<<name<<endl;
        cout<<"Rek number for "<<name<<" is "<<rekNum<<endl;
        cout<<"Price of the "<<name<<" is Rs."<<price<<endl;
    }
};

int main()
{
    int size, rekNum;
    float price;
    string name;

    cout<<"How many items information do you want to enter ?"<<endl;
    cin>>size;

    Shop* ptr = new Shop [size];
    Shop* ptrTemp = ptr;

    for(int i = 0; i < size; i++)
    {
        cout<<"Enter the name of the item no."<<i+1<<endl;
        cin>>name;
        cout<<"Enter the rek number and price of "<<name<<endl;
        cin>>rekNum>>price;

        ptr->setData(rekNum, price, name);
        ptr++;
    }
    cout<<"\nThe informations are:\n\n";
    for(int i = 0; i < size; i++)
    {
        ptrTemp->getData();
        cout<<"\n";
        ptrTemp++;
    }

    return 0;
}
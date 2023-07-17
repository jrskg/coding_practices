#include <iostream>
using namespace std;

class shop
{
    int itemId[20];
    int itemPrice[20];
    int counter;

public:
    void count(void) {
        counter = 0;
    }
    void setItem(void);
    void displayItem(void);
};

void shop :: setItem()
{
    cout<<"Enter the id of your item no."<<counter+1<<endl;
    cin>>itemId[counter];
    cout<<"Enter the price of your item no."<<counter+1<<endl;
    cin>>itemPrice[counter];
    counter++;
}

void shop :: displayItem()
{
    for(int i = 0; i < counter; i++)
    {
        cout<<"Price of your item id "<<itemId[i]<<" is Rs. "<<itemPrice[i]<<endl;
    }
}

int main()
{
    shop honey;
    honey.count();
    for(int i = 0; i < 5; i++)
    {
        honey.setItem();
    }
    honey.displayItem();

    return 0;
}

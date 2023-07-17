#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a number:";
    cin>>n;
  /*  int i=1;

    while(i<11) {
        cout<<n<<"*"<<i<<"="<<n*i<<endl;
        i++;
    };

    do {
        cout<<n<<"*"<<i<<"="<<n*i<<endl;
        i++;
    } while(i<11);
    */
    for(int i = 1; i < 11; i++)
    {
       cout<<n<<"*"<<i<<"="<<n*i<<endl;
    };

    return 0;
}

#include <iostream>
using namespace std;

int sum(int x, int y);

int main()
{
  int a, b;
  cout<<"Enter a number"<<endl;
  cin>>a;
  cout<<"Enter other number"<<endl;
  cin>>b;
  cout<<"The sum is "<<sum(a,b)<<endl;
  
	return 0;
}

int sum(int x, int y)
{
  return (x+y);
}


#include <iostream>
using namespace std;

int fib(int n)
{
  if(n < 2)
   {
     return 1;
   }
  else
   {
     return fib(n-1) + fib(n-2);
   }
}

int main()
{
	int n;
 cout<<"Enter a number"<<endl;
 cin>>n;
 cout<<"The fibonacci num at "<<n<<" is "<<fib(n)<<endl;
	return 0;
}
    
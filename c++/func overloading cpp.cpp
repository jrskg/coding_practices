#include <iostream>
using namespace std;

float volume(int r, int h)
{
  return (3.14*r*r*h);
}

float volume(int l, int b, int h)
{
  return (l*b*h);
}

float volume(int a)
{
  return (a*a*a);
}

int main()
{
	cout<<"The volume of cylinder is "<<volume(7,8)<<endl;
 cout<<"The volume of cube is "<<volume(7)<<endl;
 cout<<"The volume of rectangle is "<<volume(2, 4, 6)<<endl;
 
	return 0;
}

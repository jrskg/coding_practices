#include <iostream>
using namespace std;

int main()
{
	 int marks[] = {23,11,36,16,66};
  /* for(int i = 0; i < 5; i++)
      {
        cout<<marks[i]<<endl;
      }
  */

  int* ptr = marks;
  
  cout<<"The address of 1st element is "<<ptr<<endl;
  cout<<"The address of 1st element is "<<marks<<endl;
  cout<<"The value of 1st element is "<<*ptr<<endl;
  cout<<"The value of 2st element is "<<*(ptr+1)<<endl;
  

	return 0;
}

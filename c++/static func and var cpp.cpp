#include <iostream>
using namespace std;

class Employee
{
  private:
     int id;
     static int count;
  public:
     void setdata(void);
     void getdata(void);
     static void display(void);
};

void Employee::setdata()
{
  cout<<"Enter your employee id"<<endl;
  cin>>id;
  count++;
}

void Employee::getdata()
{
  cout<<"The id of employee no."<<count<<" is "<<id<<endl;
}

int Employee::count;

void Employee::display()
{
   cout<<"The value of count is "<<count<<endl<<endl;
}

int main()
{
	 Employee suraj, honey, prince;
  suraj.setdata();
  suraj.getdata();
  Employee::display();

  honey.setdata();
  honey.getdata();
  Employee::display();

  prince.setdata();
  prince.getdata();
  Employee::display();

	return 0;
}

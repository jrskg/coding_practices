#include <iostream>
using namespace std;

class suraj{
   
    int id;
    int salary;
    
    public:
    void getIdSalary(void);
    void displayIdSalary(void);
};

void suraj::getIdSalary()
{
   cout<<"Enter the id"<<endl;
   cin>>id;
   cout<<"Enter the salary"<<endl;
   cin>>salary;
}

void suraj::displayIdSalary()
{
   cout<<"The id is "<<id<<endl;
   cout<<"The salary is "<<salary<<endl;
}
int main()
{  suraj skg,sks;
  skg.getIdSalary();
  skg.displayIdSalary();

  sks.getIdSalary();
  sks.displayIdSalary();

	return 0;
}

#include <iostream>
using namespace std;

class complex;

class calculator
{
  public:
    int sumReal(complex, complex);
    int sumImg(complex, complex);

};

class complex
{
  int a, b; 
  
 // friend int calculator::sumReal(complex o1, complex o2);
 // friend int calculator::sumImg(complex o1, complex o2);
    friend class calculator;
  
  public:
    void setNum(int v1, int v2)
     {
       a = v1;
       b = v2;
     }
    void printNum(void)
     {
       cout<<"The imaginery number is "<<a<<" + "<<b<<"i"<<endl;
     }
};

int calculator::sumReal(complex o1, complex o2)
      {
        return o1.a + o2.a;
      }
int calculator::sumImg(complex o1, complex o2)
     {
        return o1.b + o2.b;
     }

int main()
{
	 complex o1, o2;
  o1.setNum(4, 5);
  o1.printNum();

  o2.setNum(6, 4);
  o2.printNum();

  calculator calc;
  int result = calc.sumReal(o1, o2);
  int result1 = calc.sumImg(o1, o2);

  cout<<"The sum of real part is "<<result<<endl;
  cout<<"The sum of imaginery part is "<<result1<<endl;

	return 0;
}

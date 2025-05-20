#include <iostream>
using namespace std;

class Shape{
public:
  virtual double area() = 0;
};
class TwoDShape : public Shape{};
class ThreeDShape : public Shape{
public:
  virtual double volume() = 0;
};

class Square : public TwoDShape{
private:
  double side;
public:
  Square(double side){
    this->side = side;
  }
  double area(){
    return side*side;
  }
};

class Rectangle : public TwoDShape{
private:
  double length;
  double breadth;
public:
  Rectangle(double l, double b){
    this->length = l;
    this->breadth = b;
  }
  double area(){
    return length*breadth;
  }
};

class Cube : public ThreeDShape{
private:
  double l;
  double b;
  double h;
public:
  Cube(double l, double b, double h){
    this->l = l;
    this->b = b;
    this->h = h;
  }

  double area(){
    return l * b;
  }
  double volume(){
    return l*b*h;
  }
};

int main() {
  
  ThreeDShape* c = new Cube(1,2,3);
  cout<<c->volume()<<endl;


  TwoDShape* r = new Rectangle(1,2);
  cout<<r->area()<<endl;
  return 0;
}
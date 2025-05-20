#include <iostream>
using namespace std;

class Shape{
public:
  virtual double area() = 0;
  virtual double volume() = 0;
};

class Square : public Shape{
private:
  double side;
public:
  Square(double side){
    this->side = side;
  }
  double area(){
    return side*side;
  }
  double volume(){
    throw logic_error("Volume not allowed in 2D shapes");
  }
};

class Rectangle : public Shape{
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
  double volume(){
    throw logic_error("Volume not allowed in 2D shapes");
  }
};

class Cube : public Shape{
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
  Shape* c = new Cube(1,2,3);
  cout<<c->volume()<<endl;
  return 0;
}
#include <iostream>
using namespace std;

class Parent{
    public:
    int height;
    int weight;

    public:
    void setHeight(int height){
        this->height = height;
    }
    void setWeight(int weight){
        this->weight = weight;
    }
    int getHeight(){
        return this->height;
    }
    int getWeight(){
        return this->weight;
    }
};

class Child : public Parent{
    public:
    string color;

    public:
    void setColor(string color){
        this->color = color;
    }

    string getColor(){
        return this->color;
    }
};

int main() {
    /*              
                    public      protected       private

        public      public      protected       private

        protected   protected   protected       private

        private     NA          NA              NA

        NA ----> Not Accessible
    
    */

   /*
        Both protected and private members are not accessible outside the class, but protected members can be accessed by 
        derived classes, whereas private members cannot be accessed by any derived class.
   */

    Child c1;
    c1.setWeight(34);
    c1.setHeight(6);
    c1.setColor("Red");

    cout<<c1.getColor()<<endl;
    cout<<c1.getHeight()<<endl;
    cout<<c1.getWeight()<<endl;
    
    return 0;
}
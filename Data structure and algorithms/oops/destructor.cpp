#include <iostream>
using namespace std;

class Car{
    public:
    string name;
    int id;
    int totalWheels;
    bool isSuperCar;
    
    //this is a static variable which belongs to class not to any instance(object) of this class 
    static int stVar;

    static int stFunc(){
        //-->No need to create instance to access this function can be called using the class
        //-->It can only access static variables of this class
        //-->Since it doesn't belongs to any instance or object it doesn't have 'this' keyword
        return stVar;
    }

    //here initialization list is used to initialize the member variables rather than assigning it inside the constructor body
    Car(string name, int id, int totalWheels, bool isSuperCar):name(name), id(id), totalWheels(totalWheels), isSuperCar(isSuperCar) {
        // this->name = name;
        // this->id = id;
        // this->totalWheels = totalWheels;
        // this->isSuperCar = isSuperCar;
    }

    //printing all the details
    void printDetails(){
        string str = isSuperCar ? "Yes" : "No";
        cout<<endl<<"Name : "<<name<<endl;
        cout<<"id : "<<id<<endl;
        cout<<"Total wheels : "<<totalWheels<<endl;
        cout<<"Is a super car ?  "<<str<<endl<<endl;
    }
    ~Car(){
        //destructor has no parameter and when you create instance of object statically then it is called automatically but in case of dynamic you have to call it manually
        cout<<"Dectructor called"<<endl;
    }
};

int Car::stVar = 10;

int main() {
    //destructor is called automatically
    Car c("Bugati", 101, 4, true);
    c.printDetails();

    //destructor is not called automatically
    Car * c1 = new Car("Lamborghini", 102, 4, true);
    c1->printDetails();

    cout<<Car::stVar<<endl;
    cout<<Car::stFunc()<<endl;

    delete c1;
    return 0;
}
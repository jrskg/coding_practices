#include <iostream>
#include <string.h>
using namespace std;

class Employee{
    public:
    string name;
    int eId;
    string language;
    string role;
    char *address;

    //default constructor
    Employee(){
        cout<<"I am a default constructor"<<endl;
    }

    //parameterized constructor
    Employee(string name, int eId, string language, string role, char *address){
        //note this keyword is a pointer to the current instance of the class, means this keyword pointing to the same memory address as the name of the instance of the class is pointing
        char * ch = new char(sizeof(address));
        strcpy(ch, address);
        this->address = ch;
        this->name = name;
        this->eId = eId;
        this->language = language;
        this->role = role;
        //also free the allocated memory
    }

    Employee(Employee& temp){
        //if you pass by value then it wiil throw error cause it goes in infinite loop type situation so always use pass by reference 
        this->name = temp.name;
        this->eId = temp.eId;
        this->language = temp.language;
        this->role = temp.role;
        char * ch = new char(sizeof(temp.address));
        strcpy(ch, temp.address);
        this->address = ch;

        //also free the allocated memory
    }

    void printDetails(){
        cout<<endl<<"My name is "<<name<<endl;
        cout<<"My eId is "<<eId<<endl;
        cout<<"And i code in "<<language<<" language"<<endl;
        cout<<"My role in the company is "<<role<<endl;
        cout<<"I am from "<<address<<endl<<endl<<endl;
    }
};

int main() {

    // Employee *e1 = new Employee("Suraj Gupta", 101, "JavaScript", "Mern-Stack Developer");
    // e1->printDetails();

    // Employee *e2 = new Employee("John Doe", 102, "TypeScript", "React-Native Developer");
    // e2->printDetails();

    // delete e1;
    // delete e2;

    char address1[8] = "Birgunj";
    Employee e1("Suraj Gupta", 101, "JavaScript", "Mern-Stack Developer", address1);
    e1.printDetails();

    char address2[5] = "USA";
    Employee e2("John Doe", 102, "TypeScript", "React-Native Developer", address2);
    e2.printDetails();

    //default copy constructor -----> does deep copy in case or character array
    // Employee e3(e1);
    // e3.printDetails();

    // e1.address[0] = 'Z';
    // e1.printDetails();
    // e3.printDetails();

    //but we can also implement our own copy constructor ----> implemented shallow copy 
    Employee e3(e1);
    e3.printDetails();

    e1.address[0] = 'Z';
    e1.printDetails();
    e3.printDetails();


    return 0;
}
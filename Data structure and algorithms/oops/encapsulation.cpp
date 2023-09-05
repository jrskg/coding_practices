#include <iostream>
using namespace std;

class Okay{
    string name;
    string email;
    string password;
    bool isAdmin;
    int age;

    public:
    Okay(string name, string email, string password, bool isAdmin, int age): name(name), email(email), password(password), isAdmin(isAdmin), age(age) {
        cout<<"Constructor called"<<endl;
    }   

    void printInfo(){
        string str = isAdmin ? "Yes" : "No";
        cout<<endl<<"Name : "<<name<<endl;
        cout<<"Email : "<<email<<endl;
        cout<<"Password : "<<password<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"isAdmin : "<<str<<endl<<endl;
    }
};

int main() {

    //encapsulation means wrapping the data members and the methods in a instance 
    //encapsulation helps to hide the information

    Okay obj("Suraj", "sgsuraj150@gmail.com", "Okay@123", 22, true);
    obj.printInfo();
    
    return 0;
}
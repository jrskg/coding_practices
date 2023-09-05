#include <iostream>
using namespace std;

class Hero{
    string name;
    int health;
    char role;

    public:
        void setName(string n){
            name = n;
        }
        void setHealth(int h){
            health = h;
        }
        void setRole(char ch){
            role = ch;
        }

        string getName(){
            return name;
        }
        int getHealth(){
            return health;
        }
        char getRole(){
            return role;
        }
};

int main() {
    Hero suraj;

    //if the properties are public then you can access then outside the class like as below but in case of private it can be done using getters and setters
    // suraj.name = "Suraj Gupta";
    // suraj.health = 100;
    // suraj.role = 'A';
    // cout<<suraj.name<<endl;
    // cout<<suraj.health<<endl;
    // cout<<suraj.role<<endl;

    suraj.setName("Okay");
    suraj.setHealth(100);
    suraj.setRole('A');

    cout<<suraj.getName()<<endl;
    cout<<suraj.getHealth()<<endl;
    cout<<suraj.getRole()<<endl;

    Hero *ram = new Hero();
    (*ram).setHealth(20);
    ram->setRole('B');
    (*ram).setName("Okay1");

    cout<<(*ram).getName()<<endl;
    cout<<ram->getRole()<<endl;

    return 0;
}

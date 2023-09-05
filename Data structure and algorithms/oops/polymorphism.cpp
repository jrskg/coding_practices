#include <iostream>
using namespace std;

class complex{
    int real;
    int img;

    public:
    complex(int real, int img):real(real), img(img){

    }

    void show(){
        cout<<real<<" + "<<img<<"i"<<endl;
    }

    //operator overloading +
    complex operator+(complex &second){
        int real = this->real + second.real;
        int img = this->img + second.img;

        return complex(real, img);
    }

    //operator overloading -
    complex operator-(complex &second){
        int real = this->real - second.real;
        int img = this->img - second.img;

        return complex(real, img);
    }

    //function overloading
    void greet(){
        cout<<"Hello user"<<endl;
    }
    void greet(string name){
        cout<<"Hello "<<name<<endl;
    }
    void greet(string name, int times){
        for(int i = 0; i < times; i++){
            cout<<"Hello "<<name<<endl;
        }
    }
};

int main() {

    // complex c1(3,4);
    // c1.show();

    // complex c2(4,5);
    // c2.show();

    // complex c4(1,1);
    // c4.show();

    // complex c3 = c1.operator+(c2).operator-(c4);
    // complex c3 = c1+c2-c4;
    // c3.show();

    complex ok(2,3);
    ok.greet();
    ok.greet("Suraj");
    ok.greet("Suraj",3);
    
    return 0;
}
#include <iostream>
#include <set>
using namespace std;

class Person{
  public:
  int age;
  string name, role;
  Person(int a, string n, string r){
    age = a;
    name = n;
    role = r;
  }
  bool operator < (const Person &other) const{
    return age < other.age;
  }
};

int main() {
  set<Person*> s;
  s.insert(new Person(20, "Suraj Gupta", "Developer"));
  s.insert(new Person(22, "Arbind Das", "Developer"));
  // for(auto i:s){
  //   cout<<i->name<<" "<<i->age<<" "<<i->role<<endl;
  // }

  for(auto i = s.begin(); i != s.end(); i++){
    cout<<(*i)->name<<" "<<(*i)->age<<" "<<(*i)->role<<endl;
  }
  return 0;
}
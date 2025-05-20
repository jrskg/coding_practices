#include <iostream>
using namespace std;

class Database{
public:
  virtual void save(string data)  = 0;
};

class SqlDB : public Database{
public:
  void save(string data)override{
    cout<<"Saving to sqldb"<<" name "<<data<<endl;
  }
};

class MongoDB : public Database{
public:
  void save(string data)override{
    cout<<"Saving to mongodb"<<" name "<<data<<endl;
  }
};

class UserService{
private:
  Database* db;
public:
  UserService(Database* db){
    this->db = db;
  }

  void storeUser(string name){
    this->db->save(name);
  }
};

int main() {
  UserService* u1 = new UserService(new MongoDB());
  u1->storeUser("Okay");
  UserService* u2 = new UserService(new SqlDB());
  u2->storeUser("Okay2");
  return 0;
}
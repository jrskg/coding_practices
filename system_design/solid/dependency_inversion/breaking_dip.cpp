#include <iostream>
using namespace std;

class Mongodb{
public:
  void saveToMongoDB(string name){
    cout<<"Saving to mongdb"<<" name "<<name<<endl;
  }
};

class SqlDb{
public:
  void saveToSqlDB(string name){
    cout<<"Saving to sqldb"<<" name "<<name<<endl;
  }
};

class UserService{
private:
  Mongodb* md;
  SqlDb* sd;

public:
  UserService(Mongodb* m, SqlDb* s){
    this->md = m;
    this->sd = s;
  }

  void saveToMongo(string name){
    this->md->saveToMongoDB(name);
  }

  void saveToSql(string name){
    this->sd->saveToSqlDB(name);
  }
};

int main() {
  UserService* s = new UserService(new Mongodb(), new SqlDb());
  s->saveToMongo("Okay");
  s->saveToSql("Okay2");
  return 0;
}
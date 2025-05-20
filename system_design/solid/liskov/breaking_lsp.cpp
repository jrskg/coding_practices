#include <iostream>
#include <vector>
using namespace std;

class Account{
public:
  virtual void deposit(double amount) = 0;
  virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account{
private:
  double balance;
public:
  SavingAccount(){
    this->balance = 0;
  }
  void deposit(double amount){
    balance += amount;
    cout<<"Deposited to saving account"<<endl;
  }
  void withdraw(double amount){
    if(balance >= amount){
      balance -= amount;
      cout<<"Withdrawn from saving account"<<endl;
    }else{
      cout<<"Insufficient balance"<<endl;
    }
  }
};

class CurrentAccount : public Account{
private:
  double balance;
public:
  void deposit(double amount){
    balance += amount;
    cout<<"Deposited to current account"<<endl;
  }
  void withdraw(double amount){
    if(balance >= amount){
      balance -= amount;
      cout<<"Withdrawn from current account"<<endl;
    }else{
      cout<<"Insufficient balance"<<endl;
    }
  }
};

class FixedAccount : public Account{
private:
  double balance;
public:

  void deposit(double amount){
    balance += amount;
    cout<<"Deposited to fixed account"<<endl;
  }
  void withdraw(double amount){
    throw logic_error("Withdrawal not allowed is fixed account");
  }
};

class BankClient{
private:
  vector<Account*> accounts;
public:
  BankClient(vector<Account*> accounts){
    this->accounts = accounts;
  }

  void processTransaction(){
    for(Account* acc : this->accounts){
      acc->deposit(1000);
      try{
        acc->withdraw(200);
      }
      catch(const std::exception& e){
        cout<<e.what()<<endl;
      }
    }
  }
};

int main() {
  vector<Account*> accounts;
  accounts.push_back(new SavingAccount());
  accounts.push_back(new CurrentAccount());
  accounts.push_back(new FixedAccount()); //this will break the principle as this type of account doesn't support bothe the methods

  BankClient* bc = new BankClient(accounts);
  bc->processTransaction();
  return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class DepositOnlyAccount{
public:
  virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount{
public:
  virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawableAccount{
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

class CurrentAccount : public WithdrawableAccount{
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

class FixedAccount : public DepositOnlyAccount{
private:
  double balance;
public:

  void deposit(double amount){
    balance += amount;
    cout<<"Deposited to fixed account"<<endl;
  }
};


class BankClient{
private:
  vector<DepositOnlyAccount*> depositOnlyAccounts;
  vector<WithdrawableAccount*> withdrawableAccounts;
public:
  BankClient(vector<DepositOnlyAccount*> depositOnlyAccounts, vector<WithdrawableAccount*>withdrawableAccounts){
    this->depositOnlyAccounts = depositOnlyAccounts;
    this->withdrawableAccounts = withdrawableAccounts;
  }

  void processTransaction(){
    for(WithdrawableAccount* acc : this->withdrawableAccounts){
      acc->deposit(1000);
      acc->withdraw(200);
    }

    for(DepositOnlyAccount* acc : this->depositOnlyAccounts){
      acc->deposit(1000);
    }
  }
};

int main() {
   vector<WithdrawableAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedAccount());

    BankClient* client = new BankClient (depositOnlyAccounts, withdrawableAccounts);
    client->processTransaction();

  return 0;
}
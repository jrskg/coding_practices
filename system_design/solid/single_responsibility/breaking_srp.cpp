#include <iostream>
#include <vector>
using namespace std;

class Product{
public:
  string name;
  float price;

  Product(string name, float price){
    this->name = name;
    this->price = price;
  }
};

class ShoppingCart{
private:
  vector<Product> products;
public:
  ShoppingCart(){
    this->products = {};
  }

  void addProduct(Product *p){
    this->products.push_back(*p);
  }

  float calculateTotal(){
    float total = 0;
    for(auto p : this->products){
      total += p.price;
    }
    return total;
  }

  void printInvoice(){
    for(auto p : this->products){
      cout<<p.name<<" "<<p.price<<endl;
    }
  }

  void saveToDB(){
    cout<<"Saving to db"<<endl;
  }
};

int main() {
  ShoppingCart *sc = new ShoppingCart();
  sc->addProduct(new Product("P1", 1000));
  sc->addProduct(new Product("P2", 2000));
  sc->addProduct(new Product("P3", 3000));
  cout<<sc->calculateTotal()<<endl;
  sc->printInvoice();
  sc->saveToDB();

  return 0;
}
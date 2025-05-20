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

  vector<Product> getProducts(){
    return this->products;
  }

  float calculateTotal(){
    float total = 0;
    for(auto p : this->products){
      total += p.price;
    }
    return total;
  }

  void saveToDB(){
    cout<<"Saving to db"<<endl;
  }
};

class CartInvoicePrinter{
private:
  ShoppingCart* cart;
public:

  CartInvoicePrinter(ShoppingCart* c){
    this->cart = c;
  }
  void printInvoice(){
    for(auto p : this->cart->getProducts()){
      cout<<p.name<<" "<<p.price<<endl;
    }
  }
};

class CartStorage{
private:
  ShoppingCart* cart;
public:
  CartStorage(ShoppingCart* c){
    this->cart = c;
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

  CartInvoicePrinter* p = new CartInvoicePrinter(sc);
  p->printInvoice();
  
  CartStorage* s = new CartStorage(sc);
  s->saveToDB();
  return 0;
}
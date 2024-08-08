#include <iostream>
#include <thread>
#include<unistd.h>   
using namespace std;

void taskA(string name, int n){
  for(int i = 0; i < n; i++){
    sleep(1);
    cout<<i+1<<". Running"<<name<<endl;
  }
}

int main() {
  thread t1(taskA, "Thread 1", 10), t2(taskA, "Thread 2", 15);  
  t1.join();
  t2.join();
  return 0;
}
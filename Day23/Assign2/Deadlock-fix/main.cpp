#include <iostream>
#include <thread>
#include "Country.h"

void threadFunc(Country& c);
int main(){

  Country c1;
  Country c2;
  c1.setCountry(&c2);
  c2.setCountry(&c1);

  
  std::thread t1(threadFunc, std::ref(c1));
  std::thread t2(threadFunc, std::ref(c2));

  t1.join();
  t2.join();
  std::cout << "\nExiting main\n";
  return 0;
}

void threadFunc(Country& c){

  struct Request req1 = {"Buy", "Dollar", 1.1f, 10.f};
  struct Request req2 = {"Sell", "Pounds", 1.1f, 10.f};
  for(int i = 0; i < 1000000; i++){
    c.SendRequest(&req1);
    c.SendRequest(&req2);
  }
}

#pragma once

#include "Currency.h"

class Pound: public Currency{

public:
  Pound(): Currency(){}
  Pound(float f): Currency(f){}
  Pound(const Pound& p): Currency(p){}
  Pound(Pound&& p): Currency(p){}
  
  void operator=(const Pound& p){
    if(this != &p)
      this->amt = p.amt;
  }
  
  void operator=(Pound&& p){
    if(this != &p){
      this->amt = p.amt;
      p.amt = 0;
    }
  }


};

#pragma once

#include "Currency.h"

class Yen: public Currency{
public:
  Yen(): Currency(){}
  Yen(float f): Currency(f){}
  Yen(const Yen& y): Currency(y){}
  Yen(Yen&& y): Currency(y){}

  void operator=(const Yen& y){
    if(this != &y)
      this->amt = y.amt;
  }

  void operator=(Yen&& y){
    if(this != &y){
      this->amt = y.amt;
      y.amt = 0;
    }
  }
};

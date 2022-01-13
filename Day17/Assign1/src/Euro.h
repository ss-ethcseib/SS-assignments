#pragma once
#include "Currency.h"

class Euro : public Currency{

public:
  Euro(): Currency(){}
  
  Euro(float val): Currency(val){}

  Euro(const Euro& e): Currency(e){}

  Euro(Euro&& e): Currency(e){}

  void operator=(const Euro& e){

    if(this != &e)
      this->amt = e.amt;
  }

  void operator=(Euro&& e){
    if(this == &e)
      return;

    this->amt = e.amt;
    e.amt = 0;
  }
};

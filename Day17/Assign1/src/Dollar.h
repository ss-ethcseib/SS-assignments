#pragma once
#include "Currency.h"

class Dollar : public Currency{

public:
  Dollar(): Currency(){}

  Dollar(float val): Currency(val){}

  Dollar(const Dollar& d): Currency(d){}

  Dollar(Dollar&& d): Currency(d){}

  void operator=(const Dollar& d){
    if(this != &d)
      this->amt = d.amt;
  }

  void operator=(Dollar&& d){
    if(this == &d)
      return;

    this->amt = d.amt;
    d.amt = 0;
  }
};

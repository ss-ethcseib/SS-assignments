#pragma once

#include <iostream>
#include <string>
#include <cmath>

class BigNumber{
 private:
  long int num;
 public:
  
  BigNumber(const long int* val){
    set(val);
  }
  void set(const long int*);
  long int number() const;
  void multiply(const BigNumber&, BigNumber&);
};

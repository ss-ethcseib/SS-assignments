#pragma once
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

class BigNumber{
private:
  typedef std::vector<std::vector<unsigned char>> numvec;

  bool overflow;
  union {
    long int num;
    unsigned char overflowVal[65];
  }actualNum;
  
public:
  BigNumber(const std::string* str){

    bool check = true;
    
    for(std::string::const_iterator it = str->begin(); it != str->end(); it++){
      if(!std::isdigit(*it))
        check = false;
    }
    
    if(check && std::stoll(*str) <= INT_MAX && std::stoll(*str) >= INT_MIN){
      
      set(std::stol(*str));
      overflow = false;
    }
    else{
      set(str);
      overflow = true;
    }
      
  }
  
  BigNumber(const long int val): overflow(false){
    set(val);
  }

  void set(const std::string*);
  void set(const long int);
  std::string number() const;
  void multiply(BigNumber&);
  numvec simulate_multiply(const BigNumber);
  void PrintVector(const numvec&);
};

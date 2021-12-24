#include <iostream>
#include <cassert>
#include <cstring>
#include "BigNumber.h"

bool isdigits(std::string*);
bool isdigits(char*);

int main(int argc, char** args){

  if(argc == 3){
    
    assert(isdigits(args[1]));
    assert(isdigits(args[2]));

    assert(strlen(args[1]) >= strlen(args[2]));
    
    long int int1 = std::stol(args[1]), int2 = std::stol(args[2]);

    BigNumber num1(&int1), num2(&int2);

    num1.multiply(num1, num2);

    std::cout << "Number after multiplication: " << num2.number() << std::endl;
    return 0;
  }

  else{
    std::string intStr1 = "", intStr2 = "";
    
    std::cout << "Give me two integers in base 10\n";
    std::cin >> intStr1; std::cin >> intStr2;
    
    assert(isdigits(&intStr1));
    assert(isdigits(&intStr2));

    assert(intStr1.length() >= intStr2.length());
    
    long int int1 = std::stol(intStr1), int2 = std::stol(intStr2);

    BigNumber num1(&int1), num2(&int2);

    num1.multiply(num1, num2);
    
    std::cout << "Number after multiplication: " << num2.number() << std::endl;
    return 0;
  }
  return 0;
}

bool isdigits(char* str){

  for(int i = 0; str[i] != '\0'; i++){
    if(!std::isdigit(str[i]))
      return false;
  }
  return true;
}

bool isdigits(std::string* str){

  for(std::string::iterator it = str->begin(); it != str->end(); it++){
    if(!std::isdigit(*it))
      return false;
  }
  return true;
}

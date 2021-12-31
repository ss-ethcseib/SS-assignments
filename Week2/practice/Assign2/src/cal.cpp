#include <iostream>
#include <string>
#include <cassert>
#include "Calendar.h"

bool isdigits(const char*);

int main(int argc, char** args){

  if(argc == 3){
    char* monthStr = args[1];
    char* yearStr = args[2];

    assert(isdigits(monthStr));
    assert(isdigits(yearStr));
    
    int month = std::stoi(monthStr);
    int year = std::stoi(yearStr);

    //    assert(month <= 12 && month >= 0);

    Calendar cal(month - 1, year);
    cal.print();
  }
  else{
    
    std::cout << "Please provide a month and year in the format of MM YYYY\n";
    char* monthStr = new char[2];
    char* yearStr = new char[4];
    
    std::cin >> monthStr; std::cin >> yearStr;

    assert(isdigits(monthStr));
    assert(isdigits(yearStr));

    int month = std::stoi(monthStr);
    int year = std::stoi(yearStr);

    assert(month <= 12 && month >= 0);

    Calendar cal(month - 1, year);
    cal.print();
  }
  return 0;
}

bool isdigits(const char* str){

  int i = 0;
  while(str[i] != '\0'){
    if(!std::isdigit(str[i])){
      return false;
    }
    i++;
  }
  return true;
}

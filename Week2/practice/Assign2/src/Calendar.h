#pragma once

#include <iostream>
#include <ctime>
#include <math.h>
#include <iomanip>

class Calendar{
private:
  enum months{
	      January = 0, February, March,
	      April, May, June, July, August,
	      September, October, November, December
  };
  months month;
  int year;
  static int days[12];
  int** calendar;
public:  
  Calendar(int month, int year): month(months(month)), year(year){
    
    calendar = nullptr;
    
    set(month, year);
  }

  ~Calendar(){
    if(calendar != nullptr){
      int i = 0;
      
      while(calendar[i] != nullptr){
	delete[] calendar[i];
	i++;
      }
      
      delete calendar;
    }
  }
  
  int** get() const;
  void print() const;
  void set(int month, int year);
};

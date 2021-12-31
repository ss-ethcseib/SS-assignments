#pragma once

#include <iostream>
#include <ctime>
#include <math.h>
#include <assert.h>

class Calendar{
private:
  static int days[12];
  int** calendar;
public:  
  Calendar(int month, int year){
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

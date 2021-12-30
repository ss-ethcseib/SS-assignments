#pragma once

#include <iostream>
#include <ctime>
#include <math.h>

class Calendar{
private:
  static int days[12];
  int** calendar;
public:  
  Calendar(int month, int year){
    
    set(month, year);
  }

  ~Calendar(){
    int i = 0;

    while(calendar[i] != nullptr){
      delete[] calendar[i];
      i++;
    }

    delete calendar;
  }
  
  int** get() const;
  void print() const;
  void set(int month, int year);
};

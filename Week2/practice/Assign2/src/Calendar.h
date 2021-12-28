#pragma once

#include <iostream>

class Calendar{
private:
  static int days[12];
  int** calendar;
public:  
  Calendar(int month, int year){
    
    set(month, year);
    calendar = new int**[7];
    for(int i = 0; i < 7; i++){
      calendar[i] = new int*[6];
      calendar[i][5] = nullptr;
    }

    int index = 0;
    for(int i = 0; i < days[month]; i++){
      
      calendar[i % 7][index] = i;
	if(i != 0){
	  if(i % 7 == 0)
	    index++;
	}
    }
  }
  
  int** get() const;
  void print() const;
  void set(int month, int year);
};

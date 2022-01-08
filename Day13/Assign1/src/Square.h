#pragma once

#include "Rhombus.h"

class Square: public Rhombus{

public:
  Square(): Rhombus(){}
  Square(float l){
    area = l * l;
    perimeter = 4 * l;
  }
  
  Square(Square&& sq){
    area = sq.area;
    perimeter = sq.perimeter;

    sq.area = 0;
    sq.perimeter = 0;
  }

  Square(Square& sq){
    area = sq.area;
    perimeter = sq.perimeter;
  }

  Square& operator=(Square& sq){

    if(this == &sq)
      return *this;
    
    this->area = sq.area;
    this->perimeter = sq.perimeter;

    return *this;
  }

  Square& operator=(Square&& sq){

    if(this == &sq)
      return *this;
    
    this->area = sq.area;
    this->perimeter = sq.perimeter;

    sq.area = 0;
    sq.perimeter = 0;

    return *this;
  }

  bool operator==(Square& sq){
    if(this->area == sq.area && this->perimeter == sq.perimeter)
      return true;
    return false;
  }
};

#pragma once

#include "Parallelogram.h"


class Rhombus: public Parallelogram{
 
public:

  Rhombus(): Parallelogram(){}
  Rhombus(float d1, float d2, float side){
    area = 0.5f * d1 * d2;
    perimeter = 4 * side;
  }

  Rhombus(Rhombus&& rh){
    area = rh.area;
    perimeter = rh.perimeter;

    rh.area = 0;
    rh.perimeter = 0;
  }

  Rhombus(Rhombus& rh){
    area = rh.area;
    perimeter = rh.perimeter;
  }

  Rhombus& operator=(Rhombus&& rh){

    if(this == &rh)
      return *this;
    
    this->area = rh.area;
    this->perimeter = rh.perimeter;

    rh.area = 0;
    rh.perimeter = 0;

    return *this;
  }

  Rhombus& operator=(Rhombus& rh){

    if(this == &rh)
      return *this;
    
    this->area = rh.area;
    this->perimeter = rh.perimeter;
    
    return *this;
  }

  bool operator==(Rhombus& rh){
    if(this->area == rh.area && this->perimeter == rh.perimeter)
      return true;
    return false;
  }
};

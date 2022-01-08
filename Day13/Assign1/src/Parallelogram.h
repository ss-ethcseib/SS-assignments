#pragma once

#include "Quadrilateral.h"

class Parallelogram: public Quadrilateral{

public:

  Parallelogram(): Quadrilateral(){}
  Parallelogram(float b, float h){
    area = b * h;
    perimeter = 2 * b + 2 * h;
  }

  Parallelogram(Parallelogram&& par){
    area = par.area;
    perimeter = par.perimeter;

    par.perimeter = 0;
    par.area = 0;
  }

  Parallelogram(Parallelogram& par){
    area = par.area;
    perimeter = par.perimeter;
  }

  Parallelogram& operator=(Parallelogram&& par){

    if(this == &par)
      return *this;
    
    this->area = par.area;
    this->perimeter = par.perimeter;

    return *this;
  }

  Parallelogram& operator=(Parallelogram& par){

    if(this == &par)
      return *this;
    
    this->area = par.area;
    this->perimeter = par.perimeter;

    return *this;
  }

  bool operator==(Parallelogram& par){
    if(this->area == par.area && this->perimeter == par.perimeter)
      return true;
    return false;
  }
};

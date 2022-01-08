#pragma once

#include "Parallelogram.h"

class Rectangle: public Parallelogram{

public:
  Rectangle(): Parallelogram(){}
  Rectangle(float l, float w){
    area = l * w;
    perimeter = 2 * l + 2 * w;
  }

  Rectangle(Rectangle& rec){
    area = rec.area;
    perimeter = rec.perimeter;
  }
  
  Rectangle(Rectangle&& rec){
    area = rec.area;
    perimeter = rec.perimeter;

    rec.area = 0;
    rec.perimeter = 0;
  }

  Rectangle& operator=(Rectangle&& rec){

    if(this == &rec)
      return *this;
    
    this->area = rec.area;
    this->perimeter = rec.perimeter;

    rec.perimeter = 0;
    rec.area = 0;

    return *this;
  }

  Rectangle& operator=(Rectangle& rec){

    if(this == &rec)
      return *this;
    
    this->area = rec.area;
    this->perimeter = rec.perimeter;

    return *this;
  }

  bool operator==(Rectangle& rec){

    if(this->area == rec.area && this->perimeter == rec.perimeter)
      return true;
    return false;
  }
};

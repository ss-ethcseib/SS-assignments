#pragma once

#include "Parallelogram.h"

class Rectangle: public Parallelogram{
private:
  float l;
  float w;

public:
  Rectangle(): l(0), w(0){}
  Rectangle(float l, float w): l(l), w(w){}

    float Area(){
    return l * w;
  }

  float Perimeter(){
    return 2 * l + 2 * w;
  }

};

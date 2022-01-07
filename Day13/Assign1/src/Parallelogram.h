#pragma once

#include "Quadrilateral.h"

class Parallelogram: public Quadrilateral{
private:
  float b;
  float h;
  
public:

  Parallelogram(): b(0), h(0){}
  Parallelogram(float b, float h): b(b), h(h){}
  
  float Area(){
    return b * h;
  }

  float Perimeter(){
    return 2 * b + 2 * h;
  }
};

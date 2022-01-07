#pragma once

#include "Quadrilateral.h"

class Parallelogram: public Quadrilateral{
private:
  float b;
  float h;
  
public:

  float Area(){
    return b * h;
  }

  float Perimeter(){
    return 2 * b + 2 * h;
  }
};

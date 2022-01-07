#pragma once

#include "Parallelogram.h"


class Rhombus: public Parallelogram{

private:
  float d1;
  float d2;
  float side;
 
public:

  Rhombus(): d1(0), d2(0), side(0){}
  Rhombus(float d1, float d2, float side): d1(d1), d2(d2), side(side){}
  
  float Area(){
    return 0.5f * d1 * d2;
  }

  float Perimeter(){
    return 4 * side;
  }
};

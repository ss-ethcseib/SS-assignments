#pragma once

#include "Parallelogram.h"


class Rhombus: public Parallelogram{
 
public:

  Rhombus(): Parallelogram(){}
  Rhombus(float d1, float d2, float side){
    area = 0.5f * d1 * d2;
    perimeter = 4 * side;
  }

  Rhombus(Parallelogram&& par){
    area = par.Area();
    perimeter = par.Perimeter();

    par.setArea(0);
    par.setPerimeter(0);
  }
};

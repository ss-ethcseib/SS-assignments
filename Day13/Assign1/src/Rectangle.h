#pragma once

#include "Parallelogram.h"

class Rectangle: public Parallelogram{

public:
  Rectangle(): Parallelogram(){}
  Rectangle(float l, float w){
    area = l * w;
    perimeter = 2 * l + 2 * w;
  }

  Rectangle(Parallelogram&& par){
    area = par.Area();
    perimeter = par.Perimeter();

    par.setArea(0);
    par.setPerimeter(0);
  }
};

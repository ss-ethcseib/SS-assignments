#pragma once

#include "Quadrilateral.h"

class Parallelogram: public Quadrilateral{

public:

  Parallelogram(): Quadrilateral(){}
  Parallelogram(float b, float h){
    area = b * h;
    perimeter = 2 * b + 2 * h;
  }

  Parallelogram(Quadrilateral&& quad){
    area = quad.Area();
    perimeter = quad.Perimeter();

    quad.setArea(0);
    quad.setPerimeter(0);
  }
};

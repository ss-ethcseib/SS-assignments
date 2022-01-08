#pragma once

#include "Quadrilateral.h"
#include "Polygon.h"

class Trapezoid: public Quadrilateral{
  
public:

  Trapezoid(Quadrilateral&& quad){
    this->setArea(quad.Area());
    perimeter = quad.Perimeter();

    quad.setArea(0);
    quad.setPerimeter(0);
  }
  
  Trapezoid(): Quadrilateral(){}
  Trapezoid(float base1, float base2, float side1, float side2, float h){

    area = 0.5 * (base1 + base2) * h;
    perimeter = base1 + base2 + side1 + side2;
  }
};

#pragma once

#include "Quadrilateral.h"

class Trapezoid: public Quadrilateral{

private:
  float side1, side2, side3, side4, h;

public:
  Trapezoid(): side1(0), side2(0), side3(0), side4(0), h(0){}
  Trapezoid(float a, float b, float h): side1(a), side2(b), side3(0), side4(0), h(h){}

  float Area(){
      return 0.5 * (side1 + side2) * h;
  }

  float Perimeter(){
    return side1 + side2 + side3 + side4;
  }

};

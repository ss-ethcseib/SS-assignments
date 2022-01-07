#pragma once

#include "Quadrilateral.h"

class Trapezoid: public Quadrilateral{

private:
  float base1, base2, side1, side2, h;

public:
  Trapezoid(): base1(0), base2(0), side1(0), side2(0), h(0){}
  Trapezoid(float base1, float base2, float side1, float side2, float h): base1(base1), base2(base2), side1(side1), side2(side2), h(h){}

  float Area(){
      return 0.5 * (base1 + base2) * h;
  }

  float Perimeter(){
    return base1 + base2 + side1 + side2;
  }

};

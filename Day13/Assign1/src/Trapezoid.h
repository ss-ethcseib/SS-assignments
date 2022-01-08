#pragma once

#include "Quadrilateral.h"
#include "Polygon.h"

class Trapezoid: public Quadrilateral{
  
public:

  Trapezoid(Quadrilateral&& quad){
    area = quad.Area();
    perimeter = quad.Perimeter();

    quad.setArea(0);
    quad.setPerimeter(0);
  }
  
  Trapezoid(): Quadrilateral(){}
  Trapezoid(const float base1, const float base2, const float side1, const float side2, const float h){

    area = 0.5 * (base1 + base2) * h;
    perimeter = base1 + base2 + side1 + side2;
  }

  Trapezoid(const Trapezoid* tr){
    area = tr->area;
    perimeter = tr->perimeter;
  }

  bool operator==(Trapezoid& tr){

    if(this->area == tr.area && this->perimeter == tr.perimeter)
      return true;
    return false;
  }
  
  Trapezoid& operator=(Trapezoid&& tr){

    if(this == &tr)
      return *this;
    
    this->area = tr.area;
    this->perimeter = tr.perimeter;

    tr.area = 0;
    tr.perimeter = 0;

    return *this;
  }

  Trapezoid& operator=(Trapezoid& tr){

    if(this == &tr)
      return *this;
    
    this->area = tr.area;
    this->perimeter = tr.perimeter;

    return *this;
  }
};

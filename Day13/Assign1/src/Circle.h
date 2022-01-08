#pragma once

#include "Ellipse.h"

class Circle: public Ellipse{
  
public:
  Circle(): Ellipse(){}
  Circle(float r){
    area = 3.14159 * r * r;
    circumference = 2 * 3.14159 * r;
    diameter = 2 * r;
  }

  Circle(Ellipse&& e){
    area = e.Area();
    circumference = e.Circumference();
    diameter = e.Diameter();

    e.setArea(0);
    e.setCircumference(0);
    e.setDiameter(0);
  }
};

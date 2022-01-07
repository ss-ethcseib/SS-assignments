#pragma once

#include "Ellipse.h"

class Circle: public Ellipse{

private:
  float r;
  
public:
  Circle(): r(0){}
  Circle(float r): r(r){}

  float Area(){
    return 3.14159 * r * r;
  }

  float Circumference(){
    return Perimeter();
  }

  float Perimeter(){
    return 2 * 3.14159 * r;
  }

  float Diameter(){
    return r * 2;
  }
};

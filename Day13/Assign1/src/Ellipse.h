#pragma once

#include "TwoDShape.h"
#include <math.h>

class Ellipse: public TwoDShape{
private:
  
  //a is the radius of the y-axis and b is the radius of the x-axis.
  float a;
  float b;
  
public:

  Ellipse(): a(0.0f), b(0.0f){}
  Ellipse(float a, float b): a(a), b(b){}
  
  float Area(){
    return 3.14159 * a * b;
  }

  float Circumference(){
    return 3.14159 * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
  }

  float Perimeter(){
    return 3.14159 * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
  }

  float Diameter(){
    return 2 * a;
  }
  
};

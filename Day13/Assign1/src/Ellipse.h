#pragma once

#include "TwoDShape.h"
#include <math.h>

class Ellipse: public TwoDShape{

protected:
  float area, circumference, diameter;
  
public:

  Ellipse(){}
  Ellipse(const float a, const float b){
    area = 3.14159 * a * b;
    circumference = 3.14159 * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
    diameter = 2 * a;
  }

  Ellipse(Ellipse&& e){
    area = e.Area();
    circumference = e.Circumference();
    diameter = e.Diameter();

    e.setArea(0);
    e.setDiameter(0);
    e.setCircumference(0);
  }
  
  const float Area() override{
    return area;
  }

  const float Circumference() override {
    return circumference;
  }

  const float Perimeter() override {
    return -1;
  }

  const float Diameter() override {
    return diameter;
  }

  void setArea(const int ar){
    if(ar > -1)
      area = ar;
  }

  void setCircumference(const int c){
    if(c > -1)
      circumference = c;
  }

  void setDiameter(const int d){
    if(d > -1)
      diameter = d;
  }
};

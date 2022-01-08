#pragma once

#include "TwoDShape.h"

class Polygon: public TwoDShape{

protected:
  float area, perimeter;

public:
  ~Polygon(){}
  Polygon(): area(0), perimeter(0){}

  const float Area() override {
    return area;
  }

  const float Perimeter() override {
    return perimeter;
  }

  void setArea(float a){
    if(a > -1)
      area = a;
  }
  
  void setPerimeter(float p){
    if(p > -1)
      perimeter = p;
  }
  
  const float Circumference() override {
    return -1;
  }
  

  virtual const float Diameter() override{
    return -1;
  }
};

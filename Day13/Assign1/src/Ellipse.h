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
    area = e.area;
    circumference = e.circumference;
    diameter = e.diameter;

    e.area = 0;
    e.diameter = 0;
    e.circumference = 0;
  }

  Ellipse(Ellipse* e){
    area = e->area;
    circumference = e->circumference;
    diameter = e->diameter;
  }

  Ellipse& operator=(Ellipse&& e){

    if(this == &e)
      return *this;
    
    this->area = e.area;
    this->diameter = e.diameter;
    this->circumference = e.circumference;

    e.area = 0;
    e.diameter = 0;
    e.circumference = 0;

    return *this;
  }

  Ellipse& operator=(Ellipse& e){

    if(this == &e)
      return *this;
    
    this->diameter = e.diameter;
    this->circumference = e.circumference;
    this->area = e.area;

    return *this;
  }

  bool operator==(Ellipse& e){
    if(area == e.area && circumference == e.circumference && diameter == e.diameter)
      return true;
    
    return false;
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

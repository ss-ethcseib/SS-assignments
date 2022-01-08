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

  Circle(Circle&& c){
    area = c.area;
    circumference = c.circumference;
    diameter = c.diameter;

    c.area = 0;
    c.circumference = 0;
    c.diameter = 0;
  }

  Circle(Circle* c){
    area = c->area;
    circumference = c->circumference;
    diameter = c->diameter;
  }

  Circle& operator=(Circle&& c){

    if(this == &c)
      return *this;
    
    this->area = c.area;
    this->circumference = c.circumference;
    this->diameter = c.diameter;
    
    return *this;
  }

  Circle& operator=(Circle& c){

    if(this == &c)
      return *this;
    
    this->area = c.area;
    this->circumference = c.circumference;
    this->diameter = c.diameter;

    return *this;
  }

  bool operator==(Circle& c){

    if(this->area == c.area && this->circumference == c.circumference &&
       this->diameter == c.diameter)
      return true;
    return false;
  }
};

#pragma once

#include "Point.h"
#include <math.h>

class Line{

private:
  Point* a;
  Point* b;
  
public:
  ~Line(){
    if(a != nullptr)
      delete a;

    if(b != nullptr)
      delete b;
  }
  
  Line(): a(new Point(0.0f, 0.0f)), b(new Point(0.0f, 0.0f)) {}
  Line(Point* a, Point* b): a(a), b(b){}

  const float Distance(){
    
    return sqrt(pow(a->getX() + b->getX(), 2) - pow(a->getY() + b->getY(), 2));
  }

  bool operator==(Line& line){
    if(this->a->getX() == line.a->getX() &&
       this->b->getY() == line.b->getY())
      return true;
    return false;
  }
};                           

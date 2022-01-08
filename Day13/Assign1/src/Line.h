#pragma once

#include "Point.h"
#include <math.h>

class Line{

private:
  Point* a;
  Point* b;
  float distance;
  
public:
  ~Line(){
    if(a != nullptr)
      delete a;

    if(b != nullptr)
      delete b;
  }
  
  Line(): a(new Point(0.0f, 0.0f)), b(new Point(0.0f, 0.0f)), distance(0) {}
  
  Line(Point* a, Point* b): a(a), b(b){
    distance = sqrt(pow(a->getX() - b->getX(), 2) + pow(a->getY() - b-\
>getY(), 2));
  }

  const float Distance(){
    
    return distance;
  }

  bool operator==(const Line& line){
    if(this->a->getX() == line.a->getX() && this->a->getY() == line.a->getY()
       && this->b->getX() == line.b->getX() && this->b->getY() == line.b->getY())
      return true;
    return false;
  }
  void Moved(){
    a = nullptr;
    b = nullptr;
  }
};                           

#pragma once

#include "Point.h"
#include <math.h>

class Line{

private:
  Point a;
  Point b;
  float distance;
  
public:
  ~Line(){

  }
  
  Line(): a(Point(0.0f, 0.0f)), b(Point(0.0f, 0.0f)), distance(0) {}
  
  Line(Point* a, Point* b): a(*a), b(*b){
    
    distance = sqrt(pow(a->getX() - b->getX(), 2) + pow(a->getY() - b->getY(), 2));
  }

  Line(Line& line){
    a = line.a;
    b = line.b;
    distance = line.distance;
  }

  Line(Line&& line){
    
    a = std::move(line.a);
    b = std::move(line.b);
    distance = line.distance;

    line.distance = 0;
  }
  
  const float Distance(){
    
    return distance;
  }

  Line& operator=(Line&& l){
    this->a = std::move(l.a);
    this->b = std::move(l.b);
    this->distance = l.distance;

    l.distance = 0;
    
    return *this;
  }

  Line& operator=(Line& l){
    this->a = l.a;
    this->b = l.b;
    this->distance = l.distance;

    return *this;
  }
  
  bool operator==(Line& line){
    if(this->a == line.a && this->b == line.b)
       return true;
    return false;
  }
};                           

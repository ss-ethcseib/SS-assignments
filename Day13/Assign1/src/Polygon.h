#pragma once

#include "TwoDShape.h"

class Polygon: public TwoDShape{

public:
  ~Polygon(){}
  Polygon(){}

  float Area(){
    return 0;
  }

  float Perimeter(){
    return 0;
  }
  
  float Circumference(){
    return -1.0;
  }

  float Diameter(){
    return -1.0;
  }
};

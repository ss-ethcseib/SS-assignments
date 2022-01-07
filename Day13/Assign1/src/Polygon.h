#pragma once

#include "TwoDShape.h"

class Polygon: public TwoDShape{

public:
  float Circumference(){
    return -1.0;
  }

  float Diameter(){
    return -1.0;
  }
};

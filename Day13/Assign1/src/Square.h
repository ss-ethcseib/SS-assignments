#pragma once

#include "Rhombus.h"

class Square: public Rhombus{

public:
  Square(): Rhombus(){}
  Square(float l){
    area = l * l;
    perimeter = 4 * l;
  }
  
  Square(Rhombus&& rh){
    area = rh.Area();
    perimeter = rh.Perimeter();

    rh.setArea(0);
    rh.setPerimeter(0);
  }
};

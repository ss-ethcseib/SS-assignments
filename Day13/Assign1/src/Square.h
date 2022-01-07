#pragma once

#include "Rhombus.h"

class Square: public Rhombus{
private:
  float l;

public:
  Square(): l(0){}
  Square(float l): l(l){}

    float Area(){
    return l * l;
  }

  float Perimeter(){
    return 4 * l;
  }

};

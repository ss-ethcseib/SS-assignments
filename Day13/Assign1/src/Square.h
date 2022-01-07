#pragma once

#include "Rhombus.h"

class Square: public Rhombus{
private:
  float l, w;

public:
  Square(): l(0), w(0){}
  Square(float l, float w): l(l), w(w){}

    float Area(){
    return l * w;
  }

  float Perimeter(){
    return 2 * l + 2 * w;
  }

};

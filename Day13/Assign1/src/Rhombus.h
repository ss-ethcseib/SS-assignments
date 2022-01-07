#pragma once

#include "Parallelogram.h"


class Rhombus: public Parallelogram{

private:
  float l;
  float w;
 
public:
  
  float Area(){
    return l * w;
  }

  float Perimeter(){
    return 2 * l + 2 * w;
  }
};

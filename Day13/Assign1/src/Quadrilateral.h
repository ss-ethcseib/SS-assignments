#pragma once

#include "Polygon.h"
#include "Triangle.h"

class Quadrilateral: public Polygon{

private:
  float side1, side2, side3, side4;
  Triangle* trs;
  
public:
  Quadrilateral(): side1(0), side2(0), side3(0), side4(0){}
  Quadrilateral(float a, float b, float c, float d): side1(a), side2(b), side3(c), side4(d){}

  Quadrilateral(Triangle* trs, float a, float b, float c, float d): trs(trs){
    Quadrilateral(a, b, c, d);
  }

  float Area(){

    float area = 0.0f;
    Triangle* head = trs;    
    while(head != nullptr){
      area += head->Area();
      head++;
    }
    
    return area;
  }

  float Perimeter(){
    return side1 + side2 + side3 + side4;
  }
};

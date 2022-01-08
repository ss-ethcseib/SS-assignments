#pragma once

class TwoDShape{

public:
  virtual ~TwoDShape(){}
  virtual const float Area() = 0;
  virtual const float Diameter() = 0;
  virtual const float Circumference() = 0;
  virtual const float Perimeter() = 0;
};

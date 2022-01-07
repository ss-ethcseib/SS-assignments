#pragma once

class TwoDShape{

public:
  virtual ~TwoDShape(){}
  virtual float Area() = 0;
  virtual float Diameter() = 0;
  virtual float Circumference() = 0;
  virtual float Perimeter() = 0;
};

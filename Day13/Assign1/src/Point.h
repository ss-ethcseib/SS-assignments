#pragma once

class Point{
  const float pntx;
  const float pnty;
public:
  Point(): pntx(0), pnty(0){}
  Point(const float pntx, const float pnty): pntx(pntx), pnty(pnty){}

  const float getX(){
    return pntx;
  }

  const float getY(){
    return pnty;
  }
};

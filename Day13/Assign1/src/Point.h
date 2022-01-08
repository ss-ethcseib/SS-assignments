#pragma once

class Point{
  float pntx;
  float pnty;
  
public:
  Point(): pntx(0), pnty(0){}
  Point(const float pntx, const float pnty): pntx(pntx), pnty(pnty){}
  Point(const Point& pnt){
    pntx = pnt.pntx;
    pnty = pnt.pnty;
  }

  Point(Point&& pnt){
    pntx = pnt.pntx;
    pnty = pnt.pnty;

    pnt.pntx = 0;
    pnt.pnty = 0;
  }

  Point& operator=(Point&& pnt){
    this->pntx = pnt.pntx;
    this->pnty = pnt.pnty;

    pnt.pntx = 0;
    pnt.pnty = 0;

    return *this;
  }

  Point& operator=(const Point& pnt){
    this->pntx = pnt.pntx;
    this->pnty = pnt.pnty;

    return *this;
  }

  bool operator==(Point& pnt){
    if(this->pntx == pnt.pntx && this->pnty == pnt.pnty)
      return true;
    return false;
  }
  
  const float getX(){
    return pntx;
  }

  const float getY(){
    return pnty;
  }
};

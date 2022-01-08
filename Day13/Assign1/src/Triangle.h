#pragma once

#include "Polygon.h"
#include "Multi_Line.h"
#include "Point.h"
#include "Line.h"

class Triangle: public Polygon{

private:

  Multi_Line lines;
  
public:
  ~Triangle(){}
  
  Triangle(): Polygon(){

    lines(new Line(new Point(0.0f, 0.0f), new Point(0.5f, 1.0f)));
    lines(new Line(new Point(0.5f, 1.0f), new Point(1.0f, 0.0f)));
    lines(new Line(new Point(1.0f, 0.0f), new Point(0.0f, 0.0f)));
    lines(nullptr);
  }
  
  Triangle(Point* a, Point* b, Point* c, const float h){
    
    lines(new Line(a, b));
    lines(new Line(b, c));
    lines(new Line(c, a));
    lines(nullptr);

    this->area = 0.5 * lines[2]->Distance() * h;
    this->perimeter = lines[0]->Distance() + lines[1]->Distance() + lines[2]->Distance();

  }

  Triangle(Triangle&& tr){

    lines = std::move(tr.lines);

    area = tr.area;
    perimeter = tr.perimeter;
    tr.area = 0;
    tr.perimeter = 0;
  }

  Triangle(Triangle& tr){
    
    lines = tr.lines;
    area = tr.area;
    perimeter = tr.perimeter;
  }

  Triangle& operator=(Triangle&& tr){
      
    this->area = tr.area;
    this->perimeter = tr.perimeter;
    this->lines = std::move(tr.lines);
    
    tr.area = 0;
    tr.perimeter = 0;

    return *this;
  }

  Triangle& operator=(Triangle& tr){
    
    this->lines = tr.lines;
    this->area = tr.area;
    this->perimeter = tr.perimeter;

    return *this;
  }
  
  Line& operator[](int index){
    return *(lines[index]);
  }
  
  bool operator==(Triangle& tr){

    if(this->area == tr.area && this->perimeter == tr.perimeter)
      return true;
    return false;
  }
  
  Line& compareTrianglePoints(Triangle& tr){

    int index = 2;
    for(int i = 0; i < 3; i++){
      for(int x = 0; x < 3; x++){
	if(*this->lines[i] == *tr.lines[x]){
	  index = i;
	}
      }
    }
    
    return *lines[index];
  }
};

#pragma once

#include "Polygon.h"
#include "Multi_Line.h"
#include "Point.h"
#include "Line.h"

class Triangle: public Polygon{

private:

  float h;
  Multi_Line lines;
  
public:
  Triangle(): h(0){
    lines(new Line(new Point(0.0f, 0.0f), new Point(0.5f, 1.0f)));
    lines(new Line(new Point(0.5f, 1.0f), new Point(1.0f, 0.0f)));
    lines(new Line(new Point(1.0f, 0.0f), new Point(0.0f, 0.0f)));
    lines(nullptr);
  }
  
  Triangle(Point* a, Point* b, Point* c, const float h): h(h){

    lines(new Line(a, b));
    lines(new Line(b, c));
    lines(new Line(c, a));
    lines(nullptr);
  }
  
  float Area(){
    return 0.5 * lines[2]->Distance() * h;
  }

  float Perimeter(){
    return lines[0]->Distance() + lines[1]->Distance() + lines[2]->Distance();
  }

  float compareTrianglePoints(Triangle& tr){

    float lineLength = 0;
    for(int i = 0; i < 3; i++){
      for(int x = 0; x < 3; x++){
	if(this->lines[i] == tr.lines[x]){
	  
	  lineLength = this->lines[i]->Distance();
	}
      }
    }
    return lineLength;
  }
};

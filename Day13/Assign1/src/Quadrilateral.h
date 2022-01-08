#pragma once

#include "Polygon.h"
#include "Triangle.h"

class Quadrilateral: public Polygon{

public:

  ~Quadrilateral(){}

  Quadrilateral(): Polygon(){}

  Quadrilateral(Quadrilateral&& q){
    perimeter = q.perimeter;
    area = q.area;

    q.perimeter = 0;
    q.area = 0;
  }

  Quadrilateral(Quadrilateral& q){
    perimeter = q.perimeter;
    area = q.area;
  }

//This is interesting because I started to implement a  
//system where you create shapes by creating triangles
//and combining them. Every shape, excluding ellipses
//and their subset, can be done this way. I didn't fully
//implement this because it would take days. I only
//implemented this for this class because it seemed easier.
//This version is incredibly simple and not dynamic though.
//This is used alot in graphics rendering software.
  Quadrilateral(Triangle** trs){

    perimeter = 0;
    area = 0;

    if(trs != nullptr){
      
      int count = 0;
      Line line = trs[0]->compareTrianglePoints(*trs[1]);

      int i = 0;
      while(trs[i] != nullptr){
        for(int x = 0; x < 3; x++){
	  if(count != 2 && line.Distance() == trs[i][0][x].Distance()){
	    count++;
	  }
	  else{
	    perimeter += trs[i][0][x].Distance();
	  }
	}
	i++;
      }

      i = 0;
      while(trs[i] != nullptr){
	area += trs[i]->Area();
	i++;
      }
    }
  }

  bool operator==(Quadrilateral& q){

    if(this->area == q.area && this->perimeter == q.perimeter)
      return true;
    return false;
  }
  
  Quadrilateral& operator=(Quadrilateral&& q){

    if(this == &q)
      return *this;
    
    this->area = q.area;
    this->perimeter = q.perimeter;

    q.perimeter = 0;
    q.area = 0;

    return *this;
  }

  Quadrilateral& operator=(Quadrilateral& q){

    if(this == &q)
      return *this;
    
    this->area = q.area;
    this->perimeter = q.perimeter;

    return *this;
  }
};

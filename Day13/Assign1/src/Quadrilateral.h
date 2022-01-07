#pragma once

#include "Polygon.h"
#include "Triangle.h"

class Quadrilateral: public Polygon{

private:
  float perimeter;
  float area;
  
public:

  ~Quadrilateral(){}

  Quadrilateral(){
    perimeter = 0;
    area = 0;
  }

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
  
  float Area(){
    
    return area;
  }

  float Perimeter(){
    return perimeter;
  }
};

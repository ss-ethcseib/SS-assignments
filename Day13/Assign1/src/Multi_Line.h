#pragma once

#include "Line.h"
#include <vector>

class Multi_Line{
private:
  std::vector<Line*> lines;
public:
  ~Multi_Line(){
    if(!lines.empty()){

      for(std::vector<Line*>::iterator it = lines.begin();
	  it != lines.end(); it++)
	delete *it;
    }
  }
  
  Multi_Line(){
    
  }

  void operator()(Line* line){
    this->lines.push_back(line);
  }

  Line*& operator[](const int index){
    return this->lines[index];
  }
};

#pragma once

#include "Line.h"
#include <vector>

class Multi_Line{
private:
  std::vector<Line*> lines;

  void Delete(){

    if(!lines.empty()){
      for(std::vector<Line*>::iterator it = lines.begin();
	  it != lines.end(); it++)
	if(*it != nullptr)
	  delete *it;
      lines.clear();
    }
  }
  
  void Move(){
    
    if(!lines.empty()){
      for(std::vector<Line*>::iterator it = lines.begin();	
	  it != lines.end(); it++)
	
	*it = nullptr;
      
      lines.clear();
    }
  }
  
public:
  ~Multi_Line(){
    Delete();
  }
  
  Multi_Line(){
    
  }
  
  void operator()(Line* line){
    this->lines.push_back(line);
  }

  Line*& operator[](const int index){
    return this->lines[index];
  }

  Multi_Line& operator=(Multi_Line&& ml){

    this->Delete();

    this->lines = ml.lines;

    ml.Move();

    return *this;
  }

  Multi_Line& operator=(Multi_Line& ml){
    this->Delete();

    for(std::vector<Line*>::iterator it = ml.lines.begin(); it != ml.lines.end(); it++){
      this->lines.push_back(new Line(**it));
    }
    return *this;
  }
};

#include "Utilities.h"

namespace BankParts{
  
  std::string StringToLower(std::string* str){
    
    for(std::string::iterator it = str->begin(); it != str->end(); it++){
      *it = tolower(*it);
    }
    return *str;
  }
  
  bool isdigits(std::string str){
    
    if(str == "")
      return false;
    
    for(char c: str){
      
      if(!std::isdigit(c)){
	return false;	
      }    
    }
    
    return true;
  }
  
  bool isalphabet(std::string str){
    
    if(str == "")
      return false;
    
    for(char c : str){
      
      if(!std::isalpha(c))
	
	if(c != ' ')
	  return false; 
    }
    return true;
  }
}

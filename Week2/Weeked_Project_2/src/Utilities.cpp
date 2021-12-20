#include "Utilities.h"
#include <iostream>
namespace BankParts{

  std::string TrimWhiteSpace(const std::string* str){

    if(str == nullptr)
      return "";
    if(*str == "")
      return "";
    
    std::string ret = *str;
    if(ret.find_first_not_of(" ") != std::string::npos)
      ret = ret.substr(ret.find_first_not_of(" "));
    else
      return "";
    
    for(std::string::reverse_iterator it = ret.rbegin(); it != ret.rend(); it++){
      if(*it == ' '){
	ret.pop_back();
      }
      else{
	
	it = ret.rend() - 1;
      }
      
    }
    return ret;
  }
  
  std::string StringToLower(const std::string* str){

    if(*str == "")
      return *str;
    std::string param = *str;
    std::string ret = "";
    for(int i = 0; i < str->length(); i++){
      ret += tolower(param[i]);
    }
    return ret;
  }
  
  bool isdigits(const std::string* str){
    
    if(*str == "")
      return false;
    
    for(char c : *str){
      
      if(!std::isdigit(c)){
	return false;	
      }    
    }
    
    return true;
  }
  
  bool isalphabet(const std::string* str){
    
    if(*str == "")
      return false;
    
    for(char c : *str){
      
      if(!std::isalpha(c))
	
	if(c != ' ')
	  return false; 
    }
    return true;
  }
}

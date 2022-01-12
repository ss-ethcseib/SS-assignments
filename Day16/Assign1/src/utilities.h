#include <string>

void StringToLower(std::string& str){
  
  for(std::string::iterator it = str.begin(); it != str.end(); it++)
   *it = tolower(*it);
}

bool is_Hex(std::string* str){
  
  if(str->substr(0, 2) != "0x")
    return false;
  
  *str = str->substr(2);
  
  if(str->find_first_not_of("0123456789abcdefABCDEF") != std::string::npos && str[0] != ""){
    return false;
  }
  return true;
}

bool is_dec(std::string* str){
  
  if(str->find_first_not_of("0123456789") != std::string::npos)
    return false;
  return true;
}     

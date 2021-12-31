#include "log.h"


bool LOG::init(){
  /*initialized = true;
  file = std::ofstream("log.txt", std::ios::app);
  
  return file.is_open();
  */
  return true;
}

bool LOG::write(std::string* str){
  
  /*if(initialized){
    file << *str << "\n";
    return true;
  }*/
  return initialized;
}

template<class T>
bool LOG::write(T var){
  
  /*if(initialized){
    file << var << "\n";
    return true;
    }*/
  return false;
}

bool LOG::close(){
  /*
  try{
    LOG::file.close();
  }catch(...){
    return false;
    }*/
  return true;
}


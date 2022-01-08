#include <iostream>
#include <math.h>

class Exception{
private:
  float f;

public:
  Exception(float f): f(f){}
  
  void print(){
    if(f != 0){
      std::cout << "Float value " << f << " is not representable as an integer" << std::endl;

    }
    else
      std::cout << "Float value was not representable as an integer.\n";

    std::terminate();
  }
};

bool isFloat_Integer(float);

int main(int argc, char** args){
  float f1 = 1.3f;
  float f2 = 1.5f;

  std::cout << "Float values " << f1 << " " << f2 << std::endl;
  
  try{
    isFloat_Integer(f1);
  }
  catch(Exception e){
    e.print();
  }

  try{
    isFloat_Integer(f2);
  }
  catch(Exception e){
    e.print();
  }
  
  return 0;
}

bool isFloat_Integer(float f){
  
  if(floor(f) == f)
    return true;
  throw Exception(f);
  return false;
}

#include "BigNumber.h"

void BigNumber::set(const std::string* str){

  int i = 0;
  for(std::string::const_iterator it = str->begin(); it != str->end(); it++){
    actualNum.overflowVal[i++] = *it;
  }
  actualNum.overflowVal[i] = '\0';
  overflow = true;
}

void BigNumber::set(const long int val){
  actualNum.num = val;
}

std::string BigNumber::number() const{
  if(!overflow){
    return std::to_string(actualNum.num);
  }
  std::string str = "";
  for(int i = 0; i < 64; i++){
    if(actualNum.overflowVal[i] == '\0')
      i = 64;
    else
      str += actualNum.overflowVal[i];
  }
  return str;
}

void BigNumber::PrintVector(const BigNumber::numvec& vec){

  numvec::const_iterator it1 = vec.begin();
  std::vector<unsigned char>::const_iterator it2 = it1->begin();

  for(; it2 != it1->end(); it2++){
    std::cout << *it2;
  }
  std::cout << std::endl << "x";

  it1++;
  for(it2 = it1->begin(); it2 != it1->end(); it2++){
    std::cout << *it2;
  }

  int count = 1;
  for(; it1 != vec.end(); it1++){
    if(count % 2 == 0)
      std::cout << "------" << std::endl;
    for(it2 = it1->begin(); it2 != it1->end(); it2++){
      std::cout << *it2;
    }
    count++;
    std::cout << std::endl;
  }
}

BigNumber::numvec BigNumber::simulate_multiply(const BigNumber num){

  numvec vec;
  int size1 = 0;
  int size2 = 0;
  long num1 = std::stol(this->number());
  long num2 = std::stol(num.number());
  
  if(num1 < 0 && num2 < 0){
    
    size1 = std::log10(num1 * -1) + 1;
    size2 = std::log10(num2 * -1) + 1; 
  }
  else if(num1 < 0){
    
    size1 = std::log10(num1 * -1) + 1;
    size2 = std::log10(num2) + 1; 
  }
  else if(num2 < 0){
    
    size1 = std::log10(num1) + 1;
    size2 = std::log10(num2 * -1) + 1; 
  }
  else{
    
    size1 = std::log10(num1) + 1;  
    size2 = std::log10(num2) + 1;
  }
  
  if(size1 < size2){
    
    num1 = std::stol(num.number());
    num2 = std::stol(this->number());
    int tmp = size1;
    size1 = size2;
    size2 = tmp;  
  }
  //std::cout << std::endl << "  " << num1 << std::endl << "x " << num2 << std::endl << "________" << std::endl;
  
  int* arrNum1 = new int[size1];
  int* arrNum2 = new int[size2];
  std::vector<unsigned char> chars;

  arrNum1[size1 - 1] = num1 % 10;
  num1 /= 10;
  chars.push_back(arrNum1[size1 - 1]);
  std::vector<unsigned char>::iterator it = chars.begin();
  for(int i = size1 - 2; i > -1; i--){
    arrNum1[i] = num1 % 10;
    chars.insert(chars.begin(), arrNum1[i]);
    
    num1 /= 10;
  }
  vec.push_back(chars);
  chars.clear();

  for(int i = size2 - 1; i > -1; i--){
    
    arrNum2[i] = num2 % 10;  
    chars.insert(it, arrNum2[i]);
    num2 /= 10;
  }

  vec.push_back(chars);
  chars.clear();
  
  int carryOver = 0;
  long long int product = 0;
  long long int total = 0;
  int factor = 1;
  
  for(int x = size2 - 1; x > -1; x--){
    for(int y = size1 - 1; y > -1; y--){
      
      product = 0;      
      product += carryOver;
      
      carryOver = 0;
      
      product += arrNum1[y] * arrNum2[x];

      if(product > 9){
	
        carryOver = product / 10;
        product %= 10;
	
      }
      
      product = product * std::pow(10, size1 - y - 1) * factor;
      std::string str = std::to_string(product);

      for(std::string::iterator it = str.begin(); it != str.end(); it++){
	chars.push_back(*it);
      }
      vec.push_back(chars);
      chars.clear();
      total += product;
    }
    std::string str = std::to_string(total);
    for(std::string::iterator it = str.begin(); it != str.end(); it++){
      chars.push_back(*it);
    }
    vec.push_back(chars);
    chars.clear();
    
    //std::cout << "+ " << total << std::endl;
    factor = std::pow(10, size2 - x);  
  }
  
  /*if(total <= INT_MAX && total >= INT_MIN){
    output.set(total); 
  }
  else{
    std::string str = std::to_string(total);
    output.set(&str); 
    }*/
  delete[] arrNum1;
  delete[] arrNum2;

  PrintVector(vec);
  return vec;
}

void BigNumber::multiply(BigNumber& output){
  
  int size1 = 0;
  int size2 = 0;
  long num1 = std::stol(this->number());
  long num2 = std::stol(output.number());
  
  if(num1 < 0 && num2 < 0){
    size1 = std::log10(num1 * -1) + 1;  
    size2 = std::log10(num2 * -1) + 1;
  }
  else if(num1 < 0){
    size1 = std::log10(num1 * -1) + 1;
    size2 = std::log10(num2) + 1;
    
  }
  else if(num2 < 0){
    size1 = std::log10(num1) + 1;
    size2 = std::log10(num2 * -1) + 1;
  }
  else{
    size1 = std::log10(num1) + 1;
    size2 = std::log10(num2) + 1;
  }

  
  if(size1 < size2){
    num1 = std::stol(output.number());
    num2 = std::stol(this->number());
    int tmp = size1;
    size1 = size2;
    size2 = tmp;
  }
  
  std::cout << std::endl << "  " << num1 << std::endl << "x " << num2 << std::endl << "________" << std::endl;
  
  int* arrNum1 = new int[size1];
  int* arrNum2 = new int[size2];

  for(int i = size1 - 1; i > -1; i--){
    arrNum1[i] = num1 % 10;
    num1 /= 10;
  }

  for(int i = size2 - 1; i > -1; i--){
    arrNum2[i] = num2 % 10;
    num2 /= 10;
  }

  int carryOver = 0;
  long long int product = 0;
  long long int total = 0;
  int factor = 1;
  for(int x = size2 - 1; x > -1; x--){
    for(int y = size1 - 1; y > -1; y--){

      product = 0;
      product += carryOver;
      carryOver = 0;
      
      product += arrNum1[y] * arrNum2[x]; 
      
      if(product > 9){
	
	carryOver = product / 10;
	product %= 10;
      }
      product = product * std::pow(10, size1 - y - 1) * factor;

      total += product;
    }
    std::cout << "+ " << total << std::endl;
    factor = std::pow(10, size2 - x);
  }
  if(total <= INT_MAX && total >= INT_MIN){
    output.set(total);
  }
  else{
    
    std::string str = std::to_string(total);
    output.set(&str);
  }
  
  delete[] arrNum1;
  delete[] arrNum2;
}

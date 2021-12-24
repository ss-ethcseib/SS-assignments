#include "BigNumber.h"

void BigNumber::set(const long int* val){
  num = *val;
}

long int BigNumber::number() const{
  return num;
}

void BigNumber::multiply(const BigNumber& BigNum, BigNumber& output){

  /*if(std::floor(std::log10(output.number())) > std::floor(std::log10(BigNum.number()))){
    long int tmp1 = BigNum.number();
    long int tmp2 = output.number();
    BigNum.set(&tmp2);
    output.set(&tmp1);
    }*/
  
  int size1 = std::log10(BigNum.number()) + 1;
  int size2 = std::log10(output.number()) + 1;
  int num1 = BigNum.number();
  int num2 = output.number();
  
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
  int product = 0;
  long int total = 0;
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
    std::cout << std::endl << "  " << BigNum.number() << std::endl << "x " << output.number() << std::endl << "________" << std::endl << total << std::endl;
    factor = std::pow(10, size2 - x);
  }

  output.set(&total);

  delete[] arrNum1;
  delete[] arrNum2;
}

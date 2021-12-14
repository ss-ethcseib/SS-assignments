#define SIZE 25
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>

bool isdigits(std::string);

int main(void){

  int b = 0;
  
  std::string str = "";
  std::cout << "Give me a bit ammount.\n";
  std::cin >> str;

  if(str != "" && isdigits(str))
    b = std::stoi(str);
  else{
    return -1;
  }
  if(b < 1)
    return -1;
  
  long long max = pow(2, b - 1) - 1;
  unsigned long long ans = 0;
  int n = 0;
  
  while(ans <= max){

    ans = (pow(((1 + sqrt(5))/2), n) - pow(((1 - sqrt(5))/2), n))/sqrt(5);
    
    if(ans <= max)
      n++;
    else
      n--;
  }
  
  std::cout << "Max index: " << n << std::endl;

  n = 0;

  while(ans <= (pow(2, sizeof(long) * 8) / 2) - 1){
    
    ans = (pow(((1 + sqrt(5))/2), n) - pow(((1 - sqrt(5))/2), n))/sqrt(5); 
    n++;
  }
  n -= 2;  

  std::cout << "Long's max index: " << n << std::endl;
  return 0;
}

bool isdigits(std::string str){
  for(char c : str){
    if(!std::isdigit(c))
      return false;
  }
  return true;
}

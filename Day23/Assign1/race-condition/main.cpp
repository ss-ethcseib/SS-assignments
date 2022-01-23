#include <iostream>
#include <thread>
#include <math.h>

void HailStoneSeq(int&);

int main(){

  int n = 5;
  std::cout << "Expected sequence: 5, 16, 8, 4, 2, 1" << std::endl << std::endl;
  std::cout << "Output: " << n;
  while(n != 1){
    std::thread t1(HailStoneSeq, std::ref(n));
    std::thread t2(HailStoneSeq, std::ref(n));
    
    t1.join();
    t2.join();
    std::cout << ", " << n;
  }
  std::cout << std::endl << std::endl;
  
  return 0;
}

void HailStoneSeq(int& n){
  
  if(n / 2.0 == floor(n / 2)){
    n = n / 2;
  }
  else
    n = 3 * n + 1; 
}

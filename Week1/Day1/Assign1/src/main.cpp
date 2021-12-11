#include <iostream>

int fib(int, int, int);

int main(){

  int count = 5;
  std::cout << "Hello World! " << fib(0, 1, count) << " is number " << count << " in the fibonacci sequence " << std::endl;

  return 0;
}

int fib(int prev, int curr, int count){
  if(count == 1)
    return prev;
  count--;
  return fib(curr, curr + prev, count);
}

#include <iostream>

void fibonacci(int, int, int, int*);
void fibonacci(long, long, int, long*);

int main(){
  int* nums = new int[50];

  fibonacci(0, 1, 50, nums);

  std::cout << "Vals:\n\t";

  for(int i = 40; i < 50; i++)
    std::cout << i << ": " << nums[i] << "\n\t";

  std::cout << "\n\nWhat problems did you run into?\n\n";
  std::cout << "\tThe problem I ran into was integer overflow. The values being stored in the array actually began to be ngative. Not because my algorithm was wrong, but because the actual value that was being stored in the array was too large to be stored in the memory allocated for an int.\n";

  std::cout << "\n\nAt what point did you start experiencing the problems?\n";
  std::cout << "\tAt index 47 I start getting eroneous data. Index 46 is the expected outcome for the fibonacci sequence.\n";

  std::cout << "\n\n\nHow do you detect the problem?\n";
  std::cout << "\tTo detect the problem you can check against the macro INT_MAX before attepmting to store it in memmory allocated for an int.\n";

  std::cout << "\n\nDoes your compute give an error?\n";
  std::cout << "\tNo, it does not. It tries to store the number but when you access the int at that position in the array where the number is stored it gives a value that is just wrong. Could be a seemingly random negative or positive number.\n";

  long* arr = new long[200];
  
  std::cout << "\n\nLong test:\n\t";

  fibonacci(0, 1, 200, arr);
  
  for(int i = 89; i < 100; i++)
    std::cout << i <<": " << arr[i] << "\n\t";
  
  delete[] arr;
  delete[] nums;

  return 0;
}

void fibonacci(long prev, long curr, int limit, long* arr){

  arr[200 - limit] = prev;

  if(limit == 1)
    return;
  fibonacci(curr, curr + prev, limit - 1, arr);
  return;
}

void fibonacci(int prev, int curr, int limit, int* arr){

  arr[50 - limit] = prev;
  
  if(limit == 1)
    return;

  fibonacci(curr, curr + prev, limit - 1, arr);
  return;
}

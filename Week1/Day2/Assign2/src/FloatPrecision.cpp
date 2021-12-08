#include <iostream>

int main(){

  float arr[] = {5.5f, 15.5f, 155.55f, 1555.555f, 16666.6666f,255555.6f, 2555564.44f};

  std::cout << "Given an array of floats consisting of values: 5.5f\n15.5f\n155.55\n1555.555\n16666.6666\n255555.6\n2555564.44" << std::endl;
  for(float f : arr){
    std::cout << f << std::endl;
  }

  std::cout << "As the printed array shows the values get rounded up and made into scientific notation as the floating point values get larger. Thus, decreasing precision. As added evidence let's add 0.1 to 25555564.4: " << arr[6] + 0.1f << " This changes nothing. It should increment our trailing 6 by 1 due to some rounding of our decimal but does not." << std::endl;
  return 0;
}

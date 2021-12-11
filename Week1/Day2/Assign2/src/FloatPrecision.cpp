#include <iostream>
#include <iomanip>
#include <string>
int main(){

  std::cout << "The way I measured float precision was through the use of the iomanip library's setprecision function.\n I used this and the fraction 1.0f/3.0f to measure just how precise the machines can be.\n I was really surprised by the results honestly.\n From school we know that 1/3 is 0.333... When the machines calculate this this number changes.\n At some point the decimal changes from 0.3 repeated and has 4's, 5's and 7's.\n I was so interested I ran this again but using the fraction 1.0f/7.0f.\n It should be 0.142857... repeating the 142857.\n The results of the program yielded 0.14285714924335479736328125 before it stopped printing the number due to a lack of storage space for a float.\n It did not take long for this one to start having trouble with precision. \n\n";
  
  std::cout << "Tested fraction 1/3\n\n";
  for(int i = 20; i < 30; i++){
    std::cout << std::setprecision(i) << 1.0f/3.0f << std::endl;
  }
  
  std::cout << "\n\nTested fraction 1/7\n";
  for(int i = 20; i < 30; i++){
    std::cout << std::setprecision(i) << 1.0f/7.0f << std::endl;
  }
  return 0;
}

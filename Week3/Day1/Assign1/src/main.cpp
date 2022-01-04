#define SIZE 1024

#include <iostream>
#include "Sentence.h"

int main(){
  char* sent = new char[SIZE];

  std::cout << "Enter a sentence\n";
  std::cin.getline(sent, SIZE + 1);
  
  Sentence sentence1(sent);
  std::cout << "Char* submitted to constructor " << sentence1.getSentence() << std::endl << std::endl;
  
  Sentence sentence2(&sentence1);
  std::cout << "Sentence object submitted to constructor for deep copy: " << sentence2.getSentence() << std::endl << std::endl;

  Sentence sentence3;
  sentence3 = sentence2;
  std::cout << "Sentence object set equal to other Sentence object demonstrating assignment operator overloading: " << sentence3.getSentence() << std::endl << std::endl;
  
  Sentence sentence4(std::move(sentence3));
  std::cout << "Sentence object move constructor used such that old sentence is nullptr and new is \"" << sentence4.getSentence() << "\""<< std::endl << std::endl;

  Sentence sentence5;
  sentence5 = std::move(sentence4);
  std::cout << "Sentence object assigned to using assignment operator move overload such that the original sentence is nullptr and the new sentence is \"" << sentence5.getSentence() << "\"" << std::endl << std:: endl;
  delete[] sent;
  return 0;
}

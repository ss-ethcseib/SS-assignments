#include <iostream>
#include <sstream>
#include <bitset>
#include <iomanip>
#include "utilities.h"

int main(){
  std::stringstream str;
  std::string input = "";
  
  while(true){
    std::cout << std::right << std::setw(20) << "Prompt > ";
    std::getline(std::cin >> std::ws, input);
    
    
    StringToLower(input);

    if(input == "exit" || input == "quit"){
      return 0;
    }

    str << std::hex << input;
    
    std::string data[2];
    data[0] = "";
    data[1] = "";
    str >> data[0];

    if(data[0] == "hex"){
      
      str >> data[1];
      
      if(is_dec(&data[1])){

	str.seekg(0, std::ios::beg);
	str.clear();
	
	int val = -1;

        std::string tmp = "";
	
	str >> tmp;
	str >> std::dec >> val;
	std::cout << std::right << std::setw(22) << "Prompt > 0x" << std::hex << val << std::endl;
      }
      else{
	std::cerr << "\nInvalid Number\n";
      }
    }
    else if(data[0] == "bin"){

      str >> data[1];
      bool dec = is_dec(&data[1]);

      if(is_Hex(&data[1]) || dec){
        str.clear();
	
	int val = -1;

	str.seekg(3, std::ios::beg);
	
	if(dec)
	  str >> std::dec >> val;
	else
	  str >> std::hex >> val;

	std::bitset<32> bin(val);
	
	std::cout << std::right << std::setw(20) << "Prompt > " << bin << std::endl;
      }
      else
	std::cerr << "\nInvalid Number\n";
    }
    else{

      str >> data[1];
      
      if(data[1] == "+"){

	str >> data[1];

	bool dec1 = is_dec(&data[0]);
	bool dec2 = is_dec(&data[1]);
	
	if((is_Hex(&data[0]) || dec1) &&
	   (is_Hex(&data[1]) || dec2)){

	  str.clear();
	  str.seekg(0, std::ios::beg);
	  
	  
	  int val1 = -1;
	  int val2 = -1;
	  
	  if(!dec1)
	    str >> std::hex >> val1;  
	  else
	    str >> std::dec >> val1;
	  
	  str >> data[0];

	  if(!dec2)
	    str >> std::hex >> val2;
	  else
	    str >> std::dec >> val2;
	  
	  std::cout << std::right << std::setw(20) << "Prompt > " << std::dec << val1 + val2 << std::endl;
	}
	else
	  std::cerr << "\nInvalid Number\n";
      }
      else{

	bool dec = is_dec(&data[0]);
	
	if(is_Hex(&data[0]) || dec){

	  str.clear();
	  str.seekg(0, std::ios::beg);
	  
	  
	  int val = -1;
	  std::string t = "";
	  
	  
	  if(!dec){
	    str >> std::hex >> val;
	  }
	  else
	    str >> std::dec >> val;

	  std::cout << std::right << std::setw(20) << "Prompt > " << std::dec << val << std::endl;
	}
	else
	  std::cerr << "\nInvalid Number\n";
      }
    }  
    str.str(std::string());
    str.clear();
  }  
  return 0;  
}

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

void StringToLower(std::string&);

int main(){
  std::stringstream str;
  std::string input = "";
  
  while(true){
    std::cout << "Prompt > ";
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
      int val = -1;
      str >> val;
      if(val != -1)
	std::cout << "Prompt > " << val << std::endl;
    }
    else if(data[0] == "bin"){
      
      int val = -1;
      str >> val;

      std::bitset<32> bin(val);
      if(val != -1){
	std::cout << "Prompt > " << bin << std::endl;
      }
    }
    else{

      str >> data[1];
      
      if(data[1] == "+"){

	str.clear();
	str.seekg(0, std::ios::beg);

	int val1 = -1;
	int val2 = -1;

	str >> val1;
	str >> data[0];
	str >> val2;

	if(val1 != -1 && val2 != -1)
	  std::cout << "Prompt > " << val1 + val2 << std::endl;
      }
      else{
	str.clear();
	str.seekg(0, std::ios::beg);

	int val = -1;
	
	str >> val;

	if(val != -1)
	  std::cout << "Prompt > " << val << std::endl;
      }
    }

    str.str(std::string());
    str.clear();
  }
  
  return 0;
}

void StringToLower(std::string& str){
  
  for(std::string::iterator it = str.begin(); it != str.end(); it++)
   *it = tolower(*it);
  
}

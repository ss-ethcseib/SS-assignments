#include <iostream>
#include <string>
#include <unordered_map>

int main() {

	std::string val = "";
	std::unordered_map<std::string, int> primitives = { {"int", sizeof(int)},
							    {"unsigned int", sizeof(unsigned int)},
							    {"signed int", sizeof(signed int)},
							    {"short int", sizeof(short int)},
							    {"unsigned short int", sizeof(unsigned short int)},
							    {"signed short int", sizeof(signed short int)},
							    {"long int", sizeof(long int)},
							    {"signed long int", sizeof(signed long int)},
							    {"unsigned long int", sizeof(unsigned long int)},
							    {"long long int", sizeof(long long int)},
							    {"unsigned long long int", sizeof(unsigned long long int)},
							    
							    {"float", sizeof(float)}, 
							    
							    {"double", sizeof(double)},
							    {"long double", sizeof(long double)},
							    
							    {"long", sizeof(long)},
							    {"long long", sizeof(long long)},
							    
							    {"char", sizeof(char)},
							    {"unsigned char", sizeof(unsigned char)},
							    {"signed char", sizeof(signed char)},
							    
							    {"wchar_t", sizeof(wchar_t)},
							    
							    {"short", sizeof(short)},
};
	std::cin >> val;
	primitives[val] == 0 ? std::cout << "Unrecognized input\n" : std::cout << "size " << primitives[val] << std::endl;

	return 0;
}

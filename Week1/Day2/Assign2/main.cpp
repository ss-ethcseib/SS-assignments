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
														{"long long double", sizeof(long long double)},
														{"long long unsigned double", sizeof(long long unsigned double)},
														{"long long signed double", sizeof(long long signed double)},
														
														{"short double", sizeof(short double)},
														{"short short double", sizeof(short short double)},

														{"long", sizeof(long)},
														{"long long", sizeof(long long)},

														{"char", sizeof(char)},
														{"unsigned char", sizeof(unsigned char)},
														{"signed char", sizeof(signed char)},

														{"wchar_t", sizeof(wchar_t)},

														{"short", sizeof(short)}
};
	std::cin >> val;

	std::cout << primitives[val];
	return 0;
}

#include <iostream>
#include <string>
#include <math.h>

bool isdigits(std::string);
long double pow(int, int);

int main(void) {

	std::string input = "";
	long long unsigned int j = pow(2, 52);

	std::cout << "Please provide a fraction. (x/y)\n";
	std::cin >> input;

	if (input.find("/") == std::string::npos ||
		!isdigits(input.substr(0, input.find("/"))) ||
		!isdigits(input.substr(input.find("/") + 1))) {

		std::cout << "String formatting was wrong.";
		return -1;
	}

	int numerator = std::stoi(input.substr(0, input.find("/")));
	int denominator = std::stoi(input.substr(input.find("/") + 1));

	int n = 53;
	while (j >= floor((pow(2, n) * numerator) / denominator) && floor((pow(2, n) * numerator) / denominator) < pow(2, 53)) {
		
		if (floor((pow(2, n) * numerator) / denominator) <= pow(2, 53))
			n++;
		else
			n--;
	}
	
	long long unsigned int remainder = pow(2, n) * numerator;
	remainder = remainder % denominator;

	double quotient = floor((pow(2, n) * numerator) / denominator);
	if (remainder >= denominator / 2)
		quotient++;
	
	std::cout << "J = " << j << "\nN = " << n << std::endl;
	
	long double tmp = (quotient / pow(2, n)) * pow(10, 55);
	
	std::cout.precision(60);
	std::cout << "What the computer sees:\n" << tmp << std::endl;
	
	return 0;
}

bool isdigits(std::string str) {

	for (char c : str) {
		if (!std::isdigit(c))
			
			return false;
	}
	return true;
}

long double pow(int base, int exponent) {

	long double ret = 1;

	while (exponent != 0) {
		
		ret *= base;
		exponent--;
	}

	return ret;
}

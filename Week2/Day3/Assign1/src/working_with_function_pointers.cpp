#include <iostream>
#include <string>

int compute(int, int, unsigned char);
int(*funcs[])(int arg1, int arg2) = { 
	[](int arg1, int arg2)->int {return arg1 + arg2; }, 
	[](int arg1, int arg2) {return arg1 - arg2; }, 
	[](int arg1, int arg2) {return arg1 * arg2; } };



int main(void) {
	char funcmask = 1;
	
	std::cout << "Addition: 1 + 2 = " << compute(1, 2, funcmask) << std::endl;
	std::cout << "Subtraction: 1 - 2 = " << compute(1, 2, funcmask<<1) << std::endl;
	std::cout << "Multiplication: 2 * 2 = " << compute(2, 2, funcmask<<2) << std::endl;

	return 0;
}

int compute(int arg1, int arg2, unsigned char funcmask) {
	
	if (funcmask == 1)
		return funcs[0](arg1, arg2);
	else if (funcmask == 2)
		return funcs[1](arg1, arg2);
	else
		return funcs[2](arg1, arg2);

	return 0;
}
#include <iostream>
#include <string>

struct S1 {
	float y;
	void myfunc(float f) {
		y = f;
		std::cout << "Without const\n " << std::endl;
	}
};

struct S2 {
	float y;
	void myfunc(float f) const {
		y = f;
		std::cout << "\nWith const" << std::endl;
	}
};

int main(void) {

	struct S1 s1;
	s1.myfunc(8.8f);
	
	struct S2 s2;
	s2.myfunc(1.9f);
	
	return 0;
}


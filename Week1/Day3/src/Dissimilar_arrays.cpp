#include <iostream>
#include <typeinfo>

int main(void) {

	float arr[2];
	int i = 15.0f;
	float j = 2.4f;

	arr[0] = i;
	arr[1] = j;

	std::cout << "In a float array of size 2 an int is stored at position 0, " << arr[0] << ", and a float at position 1, " << arr[1] << ". The compiler does implicit conversion of the int to float which allows ints to be stored in an array of floats." << std::endl;

	std::cout << std::endl << "Position 0 type compared to original: " << typeid(arr[0]).name() << " int" << "\nPosition 1 type compared to original: " << typeid(arr[1]).name() << " float" << std::endl;
	std::cout << "\nThe previous results show that the type for our int has been converted to a float and its type has completely changed. We can not recognize it as an int anymore. So, we don't have a way to know what used to be an int and what was always a float after the ints and floats are mixed together in an array. This also works in reverse. If it was an array of ints then the floats would become ints.\n";
	
	return 0;
}

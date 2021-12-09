#include <iostream>
#include <tuple>

int main(void) {

	float arr[2];
	int i = 15.0f;
	float j = 2.4f;

	arr[0] = i;
	arr[1] = j;

	std::cout << arr[0] << " " << arr[1];
	return 0;
}

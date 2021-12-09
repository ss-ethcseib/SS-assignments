#include <vector>
#include <iostream>

int main(void) {

	int arr[] = {1, 2, 3};
	std::vector<int>* vec = new std::vector<int>(arr, arr + 3);

	int i = 0;
	for (std::vector<int>::iterator it = vec->begin(); it != vec->end(); it++) {
		std::cout << "Vector val: " << *it << "\tArray val: " << arr[i] << std::endl;
		i++;
	}
	return 0;
}

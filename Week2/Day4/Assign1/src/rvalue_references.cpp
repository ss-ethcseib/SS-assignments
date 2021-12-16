#include <iostream>
#include <string>
#include <unordered_map>
/*Ethan Seiber
12/16/2021*/

class Grade {
	std::unordered_map<int, char> grades;
public:
	Grade() {
		grades = { {10, 'D'}, {20, 'C'}, {30, 'B'}, {40, 'A'} };
	}
	char grade(const int&& score) {
		return grades[score];
	}
};
int main(void) {
	Grade g;
	int arr[] = { 10, 30, 20, 20 };

	for (int i = 0; i < 4; i++)
		std::cout << "Number grades: " << arr[i] << std::endl;

	std::cout << std::endl;

	for (int i = 0; i < 4; i++) {
		std::cout << "Letter grades: " << g.grade(std::move(arr[i])) << std::endl;
	}

	return 0;
}

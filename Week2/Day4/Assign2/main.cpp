#include <iostream>
#include "merge_sort.h"
#include <vector>

int main() {

	std::vector<Student> students = { {"james", 15}, {"tom", 67}, 
		{"tanya", 99}, {"jamie", 25}, {"john", 100}, {"thomas", 1}, 
		{"Anderson", 25} };

	MergeSort::sort(students);
	
	for (Student s : students)
		std::cout << s.studentId << " " << s.score << std::endl;

}
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

struct Student {
	std::string studentId;
	int score;
	static bool comparator(Student x, Student y) {
		if (x.score >= y.score)
			return true;
		return false;
	}
};

class MergeSort {

private:
	static void RecurseMergeSort(const int, const int, std::vector<Student>&);
	static void merge(std::vector<Student>&, const int, const int, const int);
public:
	static void sort(std::vector<struct Student>&);

};
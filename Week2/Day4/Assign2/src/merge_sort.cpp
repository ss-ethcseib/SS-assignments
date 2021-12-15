#include "merge_sort.h"

void MergeSort::RecurseMergeSort(int beginning, int end, std::vector<Student>& students) {
	
	if (beginning >= end)
		return;

	int middle = (beginning + end) / 2;

	RecurseMergeSort(beginning, middle, students);
	RecurseMergeSort(middle + 1, end, students);
	
	merge(students, beginning, middle, end);
}

void MergeSort::sort(std::vector<struct Student>& students) {

	RecurseMergeSort(0, students.size() - 1, students);
}

void MergeSort::merge(std::vector<Student>& students, const int beginning, const int middle, const int end) {

	const int size1 = middle - beginning + 1;
	const int size2 = end - middle;

	Student* arr1 = new Student[size1];
	Student* arr2 = new Student[size2];

	for (int i = 0; i < size1; i++)
		arr1[i] = students[beginning + i];

	for (int i = 0; i < size2; i++)
		arr2[i] = students[middle + i + 1];

	int index1 = 0;
	int index2 = 0;
	int index3 = beginning;

	while (index1 < size1 && index2 < size2) {
		if (Student::comparator(arr1[index1], arr2[index2])) {
			students[index3] = arr1[index1];
			index1++;
		}
		else {
			students[index3] = arr2[index2];
			index2++;
		}
		index3++;
	}

	while (index1 < size1) {
		students[index3] = arr1[index1];
		index3++;
		index1++;
	}

	while(index2 < size2){
		students[index3] = arr2[index2];
		index3++;
		index2++;
	}
	delete[] arr1;
	delete[] arr2;
}
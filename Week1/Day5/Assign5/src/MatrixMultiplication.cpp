/*Ethan Seiber
 *Dec. 10, 2021
 */
#define min(x, y) x < y ? x : y;

#include <iostream>
#include <random>
#include <assert.h>
#include <string>
#include <cmath>

int** CreateMatrix(int, int);
void DeleteMatrix(int**, int);
void PrintMatrix(int**, int, int);

int main(int argc, char** args) {

	int ADimensionX = 3;
	int ADimensionY = 2;
	int BDimensionX = 2;
	int BDimensionY = 3;

	if (argc == 5) {
	  
		try {
		 
		  ADimensionY = std::abs(std::stoi(args[1]));
		  ADimensionX = std::abs(std::stoi(args[2]));
		  BDimensionX = std::abs(std::stoi(args[3]));
		  BDimensionY = std::abs(std::stoi(args[4]));
		}
		catch (...) {
		  std::cout << "Detected bad input. Loading default matrices\n";
		  
		  ADimensionX = 3;
		  ADimensionY = 2;
		  BDimensionX = 2;
		  BDimensionY = 3;
		}
	}

	if(ADimensionY == 0 || ADimensionX == 0 || BDimensionX == 0 || BDimensionY == 0){

	  std::cout << "Detected bad input. Loading default matrices\n";
	  ADimensionX = 3;                                                                                  
	  ADimensionY = 2;                                                                                 
	  BDimensionX = 2;                                                                                 
	  BDimensionY = 3;  
	}
	//Create matrices
	int** matrixA = CreateMatrix(ADimensionX, ADimensionY);

	int** matrixB = CreateMatrix(BDimensionX, BDimensionY);

	//Check matrices dimensionality
	assert(ADimensionX == BDimensionY);

	int CDimensionX = ADimensionY;
	int CDimensionY = BDimensionX;
	
	int** matrixC = CreateMatrix(CDimensionX, CDimensionY);

	//Muliply matrices
	int matrixCX = 0;
	int matrixCY = 0;
	int matrixAX = 0;

	for (int j = 0; j < CDimensionY; j++) {
	  matrixCX = 0;
	  for (int x = 0; x < ADimensionY; x++) {
	    int sum = 0;
	    
	    for (int y = 0; y < BDimensionY; y++) {
	      sum += matrixA[matrixAX][y] * matrixB[y][x];
	    }
	    
	    matrixC[matrixCY][matrixCX] = sum;
	    
	    matrixCX++;
	  }
	  matrixAX++;
	  matrixCY++;
	}
	
	//Print matrices
	std::cout << "Matrix A:\n";
	PrintMatrix(matrixA, ADimensionX, ADimensionY);
	
	std::cout << "Matrix B:\n";
	PrintMatrix(matrixB, BDimensionX, BDimensionY);
	
	std::cout << "Matrix A multiplied with Matrix B:\n";
	PrintMatrix(matrixC, CDimensionX, CDimensionY);
        
	//Delete memory
	DeleteMatrix(matrixA, ADimensionY);
	DeleteMatrix(matrixB, BDimensionY);
	DeleteMatrix(matrixC, CDimensionY);

	return 0;
}

void DeleteMatrix(int** matrix, int y) {
	for (int i = 0; i < y; i++) {
		delete[] matrix[i];
	}
	delete matrix;
}

int** CreateMatrix(int dimensionX, int dimensionY) {

	int** matrix = new int* [dimensionY];

	for (int j = 0; j < dimensionY; j++) {
		matrix[j] = new int[dimensionX];
		for (int i = 0; i < dimensionX; i++) {
			matrix[j][i] = rand() % 5;
		}
	}

	return matrix;
}
void PrintMatrix(int** matrix, int x, int y) {
	for (int i = 0; i < y; i++) {
		
		for (int j = 0; j < x; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

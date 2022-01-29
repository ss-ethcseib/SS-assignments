#include <cassert>
#include <type_traits>
#include <utility>
#include <iostream>

template<class T>
class Matrix{

private:
  struct Dimensions{
    int x, y;
  };
  
  typedef struct Dimensions Dimensions;
  
  Dimensions dim;
  T** matrix;
  
public:

  ~Matrix(){
    if(matrix != nullptr){
      for(int i = 0; i < dim.y; i++)
	delete[] matrix[i];
      delete[] matrix;
    }
  }

  Matrix(): dim({0, 0}), matrix(nullptr){}
  
  Matrix(T**& matrix, const int y, const int x): dim({x, y}) {
    this->matrix = matrix;
    matrix = nullptr;
  }
  
  Matrix(const int y, const int x): dim({x, y}){

    if(std::is_arithmetic<T>::value){

      matrix = new T*[y];
      for(int i = 0; i < y; i++){
	matrix[i] = new T[x];
      }
    }
    else
      matrix = nullptr;
  }
  
  T* flat() const {

    T* flatArr = new T[dim.y * dim.x];

    for(int y = 0; y < dim.y; y++){
      for(int x = 0; x < dim.x; x++){
	
	flatArr[y * dim.x + x] = matrix[y][x];
       
      }
    }
    return flatArr;
  }
  
  static Matrix Multiply(const Matrix&& matrixA, const Matrix&& matrixB){

    assert(matrixA.dim.x == matrixB.dim.y);
    Matrix<int> matrixC(matrixA.dim.y, matrixB.dim.x);
    auto flatA = matrixA.flat();
    auto flatB = matrixB.flat();

#pragma omp parallel shared(matrixC) num_threads(40)
  {
#pragma omp for schedule(static)
    
    for (int i = 0;  i < matrixA.dim.y; i++) {
      int iOff = i * matrixA.dim.x;
      
      for (int j = 0; j < matrixB.dim.y; j++) {
	int jOff = j * matrixB.dim.x;
	int tot = 0;
	
	for (int k = 0; k < matrixA.dim.x; k++) {
	  
	  tot += flatA[iOff + k] * flatB[jOff + k];
	}
	matrixC.matrix[i][j] = tot;
      }
      }
  }
  delete[] flatA;
  delete[] flatB;
  
  return matrixC;
  }

  void printMatrix(){
    for(int y = 0; y < dim.y; y++){
      for(int x = 0; x < dim.x; x++){
	std::cout << matrix[y][x] << " ";
      }
      std::cout << std::endl;
    }
  }
};

int main(){
  int** interMatrix = new int*[2];
  interMatrix[0] = new int[3];
  interMatrix[1] = new int[3];
  
  for(int ii = 0; ii < 2; ii++)
    for(int i = 1; i < 4; i++)
      interMatrix[ii][i-1] = i;

  std::cout << "\nMatrix A\n";
  Matrix<int> matrixA(interMatrix, 2, 3);
  matrixA.printMatrix();
  assert(interMatrix == nullptr);

  interMatrix = new int*[3];
  for(int i = 0; i < 3; i++)
    interMatrix[i] = new int;
  for(int i = 0; i < 3; i++){
    interMatrix[i][0] = i + 4;
  }

  std::cout << "\nMultiplied by matrix B\n";
  Matrix<int> matrixB(interMatrix, 3, 1);
  matrixB.printMatrix();
  assert(interMatrix == nullptr);
  std::cout << "\n\nGives matrix C\n";
  Matrix<int> res = Matrix<int>::Multiply(std::move(matrixA), std::move(matrixB));

  res.printMatrix();
  
  return 0;
}

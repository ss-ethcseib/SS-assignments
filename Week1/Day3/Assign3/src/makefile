CFLAGS = -c -Wall -g

all: Arrays_and_vectors

Arrays_and_vectors: ArraysAndVectors.o
	clang++ -o Arrays_and_vectors ArraysAndVectors.o

ArraysAndVectors.o: ArraysAndVectors.cpp
	clang++ $(CFLAGS) ArraysAndVectors.cpp

all: Dissimilar_arrays

Dissimilar_arrays: Dissimilar_arrays.o
	clang++ -o Dissimilar_arrays Dissimilar_arrays.o

Dissimilar_arrays.o: Dissimilar_arrays.cpp
	clang++ $(CFLAGS) Dissimilar_arrays.cpp

clean:
	rm -r *.o Dissimilar_arrays Arrays_and_vectors 

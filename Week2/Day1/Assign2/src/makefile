TARGET = program

all: $(TARGET)

$(TARGET): const_and_non-const.o
	clang++ -o $(TARGET) const_and_non-const.o

const_and_non-const.o: const_and_non-const.cpp
	clang++ -c -Wall -g const_and_non-const.cpp

clean:
	rm -r $(TARGET) *.o

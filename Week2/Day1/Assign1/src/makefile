TARGET = program


all: $(TARGET)

$(TARGET): J_and_N.o
	clang++ -o $(TARGET) J_and_N.o

J_and_N.o: J_and_N.cpp
	clang++ -c -Wall -g J_and_N.cpp

clean:
	rm -r $(TARGET) *.o

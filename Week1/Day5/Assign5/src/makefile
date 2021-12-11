CFLAGS = -c -Wall -g
TARGET = MatrixMultiplication

all: $(TARGET)

$(TARGET): $(TARGET).o
	   clang++ -o $(TARGET) $(TARGET).o

bankcli.o: $(TARGET).cpp
	   clang++ $(CFLAGS) $(TARGET).cpp

clean:
	rm -r $(TARGET) *.o

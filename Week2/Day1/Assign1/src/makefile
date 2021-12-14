CFLAGS = -c -Wall -g
TARGET = Fibonacci

all: $(TARGET) $(TARGET2)

$(TARGET): $(TARGET).o
	clang++ -o $(TARGET) $(TARGET).o

$(TARGET).o: $(TARGET).cpp
	clang++ $(CFLAGS) $(TARGET).cpp

clean:
	rm -r *.o $(TARGET)

CFLAGS = -c -Wall -g
TARGET = bankcli

all: $(TARGET)

$(TARGET): bankcli.o
	   clang++ -o $(TARGET) bankcli.o

bankcli.o: bankcli.cpp
	   clang++ $(CFLAGS) bankcli.cpp

clean:
	rm -r $(TARGET) *.o
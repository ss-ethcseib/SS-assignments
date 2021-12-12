CFLAGS = -c -Wall -g
TARGET = bankcli

all: $(TARGET)

$(TARGET): bankcli.o Account.o
	   clang++ -o $(TARGET) bankcli.o Account.o

bankcli.o: bankcli.cpp
	   clang++ $(CFLAGS) bankcli.cpp

Account.o: Account.cpp
	clang++ $(CFLAGS) Account.cpp

clean:
	rm -r $(TARGET) *.o

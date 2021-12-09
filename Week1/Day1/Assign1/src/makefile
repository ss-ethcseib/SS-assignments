CFLAGS = -c -Wall -g

all: FibonacciHello

FibonacciHello: main.o
	clang++ -o FibonacciHello main.o

main.o: main.cpp
	clang++ $(CFLAGS) main.cpp

clean:
	rm -r *.o FibonacciHello

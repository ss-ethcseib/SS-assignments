target = exec
cflags = -c -Wall -g
cxxflags = -std=c++2a

all:$(target)

$(target): main.o
	g++ -o $(target) main.o

main.o: main.cpp
	g++-11 -fcoroutines $(cflags) $(cxxflags) main.cpp

clean:
	rm -r *.o $(target)

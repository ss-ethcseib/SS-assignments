target = exec
cflags = -c -Wall -g
cxxflags = -std=c++17

all:$(target)

$(target): main.o
	clang++ -o $(target) main.o -pthread
	#./$(target)

main.o: main.cpp
	clang++ $(cxxflags) $(cflags) main.cpp

clean:
	rm -r *.o $(target) 

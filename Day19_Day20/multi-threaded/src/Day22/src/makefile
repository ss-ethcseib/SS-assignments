target = exec
objs = main.o
cflags = -c -Wall -g
cxxflags = -std=c++17

all: $(target)

$(target): $(objs)
	clang++ -o $(target) $(objs) -pthread -ljsoncpp

main.o: main.cpp
	clang++ $(cflags) $(cxxflags) main.cpp

clean:
	rm -r $(target) *.o 

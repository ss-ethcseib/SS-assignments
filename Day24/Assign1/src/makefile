target = exec
objs = main.o
cxxflags = -std=c++17
cflags = -c -Wall -g

all:$(target)

$(target): $(objs)
	clang++ -o $(target) $(objs) -pthread

main.o: main.cpp
	clang++ $(cflags) $(cxxflags) main.cpp

clean:
	rm -r *.o $(target)


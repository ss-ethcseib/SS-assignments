target = exec
objs = main.o
cflags = -c -Wall -g
cxxflags = -std=c++17

all: $(target)

$(target): $(objs)
	clang++ -o $(target) $(objs) -pthread

main.o: main.cpp
	clang++ $(cxxflags) $(cflags) main.cpp

clean:
	rm -r *.o $(target) *.*~ *~

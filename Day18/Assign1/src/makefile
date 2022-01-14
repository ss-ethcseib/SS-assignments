target = tests
cflags = -c -Wall -g
objs = tests.o

all: $(target)

$(target): $(objs)
	clang++ -o $(target) $(objs) -pthread -lgtest

tests.o: tests.cpp MyVector.h
	clang++ $(cflags) tests.cpp

clean:
	rm -r *.o $(target) *.*~ *~

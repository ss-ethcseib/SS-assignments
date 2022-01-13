target1 = tests

objs = tests.o

cflags = -c -Wall -g

all: $(target1)

$(target1): $(objs)
	clang++ -o $(target1) $(objs) -pthread -lgtest

tests.o: tests.cpp
	clang++ $(cflags) tests.cpp

clean:
	rm -r *.o *.*~ *~ $(target1)

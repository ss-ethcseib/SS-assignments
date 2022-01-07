target = tests
objs = tests.o #Polygon.o Triangle.o Quadrilateral.o
cflags = -c -Wall -g

all: $(target)

$(target): $(objs)
	clang++ -o $(target) $(objs) -pthread -lgtest

tests.o: tests.cpp
	clang++ $(cflags) tests.cpp

clean:
	rm -r *.o *.*~ *~ $(target)

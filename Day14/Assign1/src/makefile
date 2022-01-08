target = test
cflags = -c -Wall -g

all:$(target)

$(target): tests.o
	clang++ -o $(target) tests.o

tests.o: tests.cpp
	clang++ $(cflags) tests.cpp

clean:
	rm -r $(target) *.o *.*~ *~ 

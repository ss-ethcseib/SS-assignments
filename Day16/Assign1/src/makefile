target1 = tests
target2 = interactive

cflags = -c -Wall -g
objs1 = tests.o
objs2 = main.o

all:$(target1) $(target2)

$(target1): $(objs1)
	clang++ -o $(target1) $(objs1) -pthread -lgtest

$(target2): $(objs2)
	clang++ -o $(target2) $(objs2)

main.o: main.cpp
	clang++ $(cflags) main.cpp

tests.o: tests.cpp
	clang++ $(cflags) tests.cpp

clean:
	rm -r *.o $(target1) $(target2) *.*~ *~


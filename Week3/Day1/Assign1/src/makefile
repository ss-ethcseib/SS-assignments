target1 = main
target2 = test
objs = Sentence.o

cflags = -c -Wall -g

all: $(target1) $(target2)

$(target1): main.o $(objs)
	clang++ -o $(target1) main.o $(objs)

main.o: main.cpp
	clang++ $(cflags) main.cpp

Sentence.o: Sentence.cpp Sentence.h
	clang++ $(cflags) Sentence.cpp

$(target2): tests.o $(objs)
	clang++ -o $(target2) tests.o $(objs) -pthread -lgtest

tests.o: tests.cpp
	clang++ $(cflags) tests.cpp

clean:
	rm -r *.o $(target1) $(target2) 

objs = cal.o Calendar.o
cflags = -c -Wall -g
target1 = cal
target2 = test

all: $(target1)

$(target1): $(objs)
	clang++ -o $(target1) $(objs)

cal.o: cal.cpp
	clang++ $(cflags) cal.cpp

Calendar.o: Calendar.cpp Calendar.h
	clang++ $(cflags) Calendar.cpp

$(target2): tests.o Calendar.o
	clang++ -o $(target2) tests.o Calendar.o -pthread -lgtest

test.o: tests.cpp
	clang++ $(cflags) tests.cpp

clean:
	rm -r *.o $(target1) $(target2)

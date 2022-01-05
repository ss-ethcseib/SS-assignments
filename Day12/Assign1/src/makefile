target2 = tests
objs = MyString.o
cflags = -c -Wall -g
libraries = -pthread -lgtest

all: $(target2)

MyString.o: MyString.cpp MyString.h
	clang++ $(cflags) MyString.cpp

$(target2): tests.o $(objs)
	clang++ -o $(target2) tests.o $(objs) $(libraries)

tests.o: tests.cpp
	clang++ $(cflags) tests.cpp 
clean:
	rm -r *.o $(target1) $(target2)

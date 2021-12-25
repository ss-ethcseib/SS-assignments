target = exec
objs = main.o BigNumber.o

cflags = -c -Wall -g

all: $(target)

$(target): $(objs)
	clang++ -o $(target) $(objs)

main.o: main.cpp
	clang++ $(cflags) main.cpp

BigNumber.o: BigNumber.cpp BigNumber.h
	clang++ $(cflags) BigNumber.cpp

test: tests.o BigNumber.o -lpthread -lgtest
	clang++ -o test tests.o BigNumber.o

tests.o: tests.cpp 
	clang++ $(cflags) tests.cpp

clean:
	rm -r *.o $(target)

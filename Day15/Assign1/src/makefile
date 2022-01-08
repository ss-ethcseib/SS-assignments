target = exec
cflags = -c -Wall -g

all:$(target)

$(target): main.o
	clang++ -o $(target) main.o

main.o: main.cpp
	clang++ $(cflags) main.cpp

clean:
	rm -r *.o $(target) *~ *.*~

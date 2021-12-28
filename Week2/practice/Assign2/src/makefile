objs = cal.o Calendar.o
cflags = -c -Wall -g
target = cal

all: $(target)

$(target): $(objs)
	clang++ -o $(target) $(objs)

cal.o: cal.cpp
	clang++ $(cflags) cal.cpp

Calendar.o: Calendar.cpp Calendar.h
	clang++ $(cflags) Calendar.cpp

clean:
	rm -r *.o $(target)

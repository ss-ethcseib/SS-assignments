target = program
objs = Person.o Static_and_singleton-ish.o

all: $(target)

$(target): $(objs)
	clang++ -o $(target) $(objs)

Person.o: Person.cpp Person.h
	clang++ -c -Wall -g Person.cpp

Static_and_singleton-ish.o: Static_and_singleton-ish.cpp
	clang++ -c -Wall -g Static_and_singleton-ish.cpp

clean:
	rm -r $(target) *.o

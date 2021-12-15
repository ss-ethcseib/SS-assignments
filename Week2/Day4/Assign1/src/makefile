target = program

all: $(target)

$(target): rvalue_references.o
	clang++ -o $(target) rvalue_references.o

rvalue_references.o: rvalue_references.cpp
	clang++ -c -Wall -g rvalue_references.cpp

clean:
	rm -r $(target) rvalue_references.o

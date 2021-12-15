target = program
obj = working_with_function_pointers.o

all: $(target)

$(target): $(obj)
	clang++ -o $(target) $(obj)

$(obj): working_with_function_pointers.cpp
	clang++ -c -Wall -g working_with_function_pointers.cpp

clean:
	rm -r $(target) $(obj)

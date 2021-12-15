target = sort
objs = merge_sort.o main.o

all: $(target)

$(target): $(objs)
	clang++ -o $(target) $(objs)

merge_sort.o: merge_sort.cpp merge_sort.h
	clang++ -c -Wall -g merge_sort.cpp

main.o: main.cpp
	clang++ -c -Wall -g main.cpp

clean:
	rm -r $(objs) $(target)

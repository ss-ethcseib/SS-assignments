TARGET1 = FloatPrecision
TARGET2 = WorkingWithTypes

CFLAGS = -c -Wall -g

all: $(TARGET1)

$(TARGET1): FloatPrecision.o
	clang++ -o $(TARGET1) FloatPrecision.o

FloatPrecision.o: FloatPrecision.cpp
	clang++ $(CFLAGS) FloatPrecision.cpp

all: $(TARGET2)

$(TARGET2): WorkingWithTypes.o
	clang++ -o $(TARGET2) WorkingWithTypes.o

WorkingWithTypes.o: WorkingWithTypes.cpp
	clang++ $(CFLAGS) WorkingWithTypes.cpp

clean:
	rm -r *.o $(TARGET1) $(TARGET2)

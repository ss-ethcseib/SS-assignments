CFLAGS = -c -Wall -g
TARGET = Binets_Formula

all: $(TARGET) 

$(TARGET): $(TARGET).o
	clang++ -o $(TARGET) $(TARGET).o

$(TARGET).o: $(TARGET).cpp
	clang++ $(CFLAGS) $(TARGET).cpp

clean:
	rm -r *.o $(TARGET) $(TARGET2)

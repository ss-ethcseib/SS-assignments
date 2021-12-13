CFLAGS = -c -Wall -g
TARGET = bankcli
OBJECTS = BankLogic.o Account.o

all: $(TARGET)

$(TARGET): main.o BankLogic.o Account.o
	   clang++ -o $(TARGET) main.o BankLogic.o Account.o

main.o: main.cpp 
	clang++ $(CFLAGS) main.cpp 

bankcli.o: BankLogic.cpp BankLogic.h
	   clang++ $(CFLAGS) BankLogic.cpp 

Account.o: Account.cpp Account.h
	clang++ $(CFLAGS) Account.cpp

test: tests

tests: tests.o $(OBJECTS)
	clang++ -o tests tests.o $(OBJECTS)

tests.o: tests.cpp
	clang++ $(CFLAGS) tests.cpp

#Account.o: Account.cpp
#	clang++ $(CFLAGS) Account.cpp

#bankcli.o: bankcli.cpp
#	clang++ $(CFLAGS) bankcli.cpp

clean:
	rm -r *.o tests $(TARGET)

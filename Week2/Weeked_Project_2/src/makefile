CFLAGS = -c -Wall -g
TARGET = bankcli
OBJECTS = BankLogic.o Account.o
cpp = -std=c++17

all: $(TARGET)

$(TARGET): main.o BankLogic.o Account.o Utilities.o 
	   clang++ -o $(TARGET) main.o BankLogic.o Account.o Utilities.o Accounts.pb.cc -lcryptopp -lprotobuf

main.o: main.cpp 
	clang++ $(cpp) $(CFLAGS) main.cpp 

bankcli.o: BankLogic.cpp BankLogic.h
	   clang++  $(CFLAGS) $(cpp) BankLogic.cpp 

Account.o: Account.cpp Account.h
	clang++ $(cpp) $(CFLAGS) Account.cpp

Utilities.o: Utilities.cpp Utilities.h
	clang++ $(cpp) $(CFLAGS) Utilities.cpp

test: tests

tests: tests.o $(OBJECTS)
	clang++ -o tests tests.o $(OBJECTS)

tests.o: tests.cpp
	clang++ $(cpp) $(CFLAGS) tests.cpp

#Account.o: Account.cpp
#	clang++ $(CFLAGS) Account.cpp

#bankcli.o: bankcli.cpp
#	clang++ $(CFLAGS) bankcli.cpp

clean:
	rm -r *.o tests $(TARGET)

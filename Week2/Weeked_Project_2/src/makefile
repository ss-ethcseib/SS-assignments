CFLAGS = -c -Wall -g
TARGET = bankcli
OBJECTS = BankLogic.o Account.o Utilities.o
cpp = -std=c++17

all: $(TARGET)

$(TARGET): main.o $(OBJECTS) 
	clang++ -o $(TARGET) main.o $(OBJECTS) Accounts.pb.cc -lcryptopp -lprotobuf 

main.o: main.cpp 
	clang++ $(cpp) $(CFLAGS) main.cpp 

BankLogic.o: BankLogic.cpp BankLogic.h
	clang++ $(cpp) $(CFLAGS) BankLogic.cpp 

Account.o: Account.cpp Account.h
	clang++ $(cpp) $(CFLAGS) Account.cpp

Utilities.o: Utilities.cpp Utilities.h
	clang++ $(cpp) $(CFLAGS) Utilities.cpp

test: tests

tests: tests.o $(OBJECTS)
	clang++ -o tests tests.o $(OBJECTS) Accounts.pb.cc -lcryptopp -lprotobuf

tests.o: tests.cpp
	clang++ $(cpp) $(CFLAGS) tests.cpp

clean:
	rm -r *.o tests $(TARGET)

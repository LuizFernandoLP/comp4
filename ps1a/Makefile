CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lboost_unit_test_framework

ps1a: FibLFSR.o test.o
	$(CC) $(CFLAGS) FibLFSR.o test.o -o ps1a $(LIBS)

all: ps1a

FibLFSR.o: FibLFSR.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c FibLFSR.cpp

test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp

clean:
	rm *o ps1a

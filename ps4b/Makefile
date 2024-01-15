CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lboost_unit_test_framework

ps4a: CircularBuffer.o test.o
	$(CC) $(CFLAGS) CircularBuffer.o test.o -o ps4a $(LIBS)

all: ps4a

CircularBuffer.o: CircularBuffer.cpp CircularBuffer.h
	$(CC) $(CFLAGS) -c CircularBuffer.cpp

test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp

clean:
	rm *o ps4a

lint:
	cpplint CircularBuffer.h CircularBuffer.cpp test.cpp main.cpp

CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lboost_unit_test_framework -lsfml-system

TextWriter: RandWriter.o TextWriter.o
	$(CC) $(CFLAGS) RandWriter.o TextWriter.o -o TextWriter $(LIBS)

all: TextWriter

RandWriter.o: RandWriter.cpp RandWriter.h
	$(CC) $(CFLAGS) -c RandWriter.cpp

TextWriter.o: TextWriter.cpp
	$(CC) $(CFLAGS) -c TextWriter.cpp

test.o: test.cpp
	        $(CC) $(CFLAGS) -c test.cpp

clean:
	rm *o TextWriter

lint:
	cpplint RandWriter.h RandWriter.cpp TextWriter.cpp test.cpp

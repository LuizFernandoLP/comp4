CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lsfml-system

EDistance: EDistance.o main.o
	$(CC) $(CFLAGS) EDistance.o main.o -o EDistance $(LIBS)

all: EDistance

EDistance.o: EDistance.cpp EDistance.h
	$(CC) $(CFLAGS) -c EDistance.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *o EDistance

lint:
	cpplint EDistance.h EDistance.cpp main.cpp

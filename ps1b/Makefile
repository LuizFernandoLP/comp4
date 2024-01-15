CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

PhotoMagic: FibLFSR.o PhotoMagic.o
	$(CC) $(CFLAGS) FibLFSR.o PhotoMagic.o -o PhotoMagic $(LIBS)

all: PhotoMagic

FibLFSR.o: FibLFSR.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c FibLFSR.cpp

PhotoMagic.o: PhotoMagic.cpp
	$(CC) $(CFLAGS) -c PhotoMagic.cpp

clean:
	rm *o PhotoMagic

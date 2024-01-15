CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

KSGuitarSim: CircularBuffer.o KSGuitarSim.o StringSound.o
	$(CC) $(CFLAGS) CircularBuffer.o KSGuitarSim.o StringSound.o -o KSGuitarSim $(LIBS)

all: KSGuitarSim

CircularBuffer.o: CircularBuffer.cpp CircularBuffer.h
	$(CC) $(CFLAGS) -c CircularBuffer.cpp

StringSound.o: StringSound.cpp StringSound.h 
	$(CC) $(CFLAGS) -c StringSound.cpp

KSGuitarSim.o: KSGuitarSim.cpp
	$(CC) $(CFLAGS) -c KSGuitarSim.cpp

clean:
	rm *o KSGuitarSim

lint:
	cpplint CircularBuffer.h CircularBuffer.cpp KSGuitarSim.cpp StringSound.h StringSound.cpp

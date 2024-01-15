CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

NBody: CelestialBody.o main.o Universe.o
	$(CC) $(CFLAGS) CelestialBody.o main.o Universe.o -o NBody $(LIBS)

all: NBody

CelestialBody.o: CelestialBody.cpp CelestialBody.h
	$(CC) $(CFLAGS) -c CelestialBody.cpp

Universe.o: Universe.cpp Universe.h
	$(CC) $(CFLAGS) -c Universe.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *o NBody

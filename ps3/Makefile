CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

ps3: Triangle.o TFractal.o
	        $(CC) $(CFLAGS) Triangle.o TFractal.o -o ps3 $(LIBS)

all: ps3

Triangle.o: Triangle.cpp Triangle.h
	        $(CC) $(CFLAGS) -c Triangle.cpp

TFractal.o: TFractal.cpp
	        $(CC) $(CFLAGS) -c TFractal.cpp

clean:
	        rm *o ps3

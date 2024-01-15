CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lboost_regex

ps7: main.o 
	$(CC) $(CFLAGS) main.o -o ps7 $(LIBS)

all: ps7

main.o: main.cpp
	        $(CC) $(CFLAGS) -c main.cpp

clean:
	rm *o ps7

lint:
	main.cpp

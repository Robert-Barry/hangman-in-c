# This Makefile is an experiment in using a build system to build C applications.

CC = gcc
OBJECTS = build/hangman.o build/wordlist.o build/hang_image.o build/game_build.o build/gameplay.o
INCLUDES = include/wordlist.h include/game_state.h include/game_build.h include/gameplay.h include/hang_image.h

all: build hangman 

build:
	mkdir -p build

hangman: $(OBJECTS)
	$(CC) -o build/hangman $(OBJECTS)

build/hangman.o: hangman.c $(INCLUDES)
	$(CC) -c hangman.c -o build/hangman.o

build/wordlist.o: src/wordlist.c include/wordlist.h
	$(CC) -c src/wordlist.c -o build/wordlist.o

build/hang_image.o: src/hang_image.c include/hang_image.h include/game_state.h
	$(CC) -c src/hang_image.c -o build/hang_image.o

build/game_build.o: src/game_build.c include/game_build.h
	$(CC) -c src/game_build.c -o build/game_build.o

build/gameplay.o: src/gameplay.c include/gameplay.h 
	$(CC) -c src/gameplay.c -o build/gameplay.o

.PHONE: clean

clean:
	rm -rf build
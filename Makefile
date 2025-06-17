# This Makefile is an experiment in using a build system to build C applications.

objects = build/hangman.o build/wordlist.o build/hang_image.o build/game_build.o build/gameplay.o
includes = include/wordlist.h include/game_state.h include/game_build.h include/gameplay.h include/hang_image.h

all: build hangman 

build:
	mkdir -p build

hangman: $(objects)
	cc -o build/hangman $(objects)

build/hangman.o: hangman.c $(includes)
	cc -c hangman.c -o build/hangman.o

build/wordlist.o: src/wordlist.c include/wordlist.h
	cc -c src/wordlist.c -o build/wordlist.o

build/hang_image.o: src/hang_image.c include/hang_image.h include/game_state.h
	cc -c src/hang_image.c -o build/hang_image.o

build/game_build.o: src/game_build.c include/game_build.h
	cc -c src/game_build.c -o build/game_build.o

build/gameplay.o: src/gameplay.c include/gameplay.h 
	cc -c src/gameplay.c -o build/gameplay.o

clean:
	rm -rf build
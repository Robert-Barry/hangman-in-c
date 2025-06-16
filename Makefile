objects = build/hangman.o build/wordlist.o build/hang_image.o

all: build hangman 

build:
	mkdir -p build

hangman: $(objects)
	cc -o build/hangman $(objects)

build/hangman.o: hangman.c include/wordlist.h
	cc -c hangman.c -o build/hangman.o

build/wordlist.o: src/wordlist.c include/wordlist.h
	cc -c src/wordlist.c -o build/wordlist.o

build/hang_image.o: src/hang_image.c include/hang_image.h include/game_state.h
	cc -c src/hang_image.c -o build/hang_image.o

clean:
	rm -rf build
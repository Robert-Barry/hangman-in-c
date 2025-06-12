objects = build/hangman.o build/wordlist.o

all: build hangman 

build:
	mkdir -p build

hangman: $(objects)
	cc -o build/hangman $(objects)

build/hangman.o: hangman.c include/wordlist.h
	cc -c hangman.c -o build/hangman.o

build/wordlist.o: src/wordlist.c include/wordlist.h
	cc -c src/wordlist.c -o build/wordlist.o

clean:
	rm -rf build
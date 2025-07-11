#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH(x)  (sizeof(x) / sizeof(x[0]))

/**
 *  getWord
 *  wordlist.c
 * 
 *  Returns a word for the game. As a word is used,
 *  the word is replaced by a '0' so this it won't be used
 *  again in subsequent games
 * 
 *  INPUTS: 
 *      none
 * 
 *  OUTPUTS: 
 *      Returns a word to be used in the hangman game.
 */
char *getWord() {
    // An array of string pointers.
    char *wordArray[] = {
        "cat", "dog", "train", "elephant", "submarine", "cabinet", "ant", "car"
    };

    // Set-up a random number to choose.
    srand(time(NULL));
    int randomNumber;

    // A char pointer to store the word chosen randomly.
    char *word;

    // Choose a random number and pick an index
    // from the words array.
    randomNumber = rand() % LENGTH(wordArray);
    word = wordArray[randomNumber];

    return word;
}

/**
 *  wordLength
 *  wordlist.c
 * 
 *  Calculates the length of a given word. 
 * 
 *  INPUTS: 
 *      char *word: a pointer to a string.
 * 
 *  OUTPUTS: 
 *      Returns the length of the word as an int. 
 */
int wordLength(char *word) {
    int count = 0;

    // Loop through the char pointer an count the number
    // of letters are in the string.
    while (*word != '\0') {
        ++count;
        ++word;
    }

    return count;
}

/**
 *  printWord
 *  wordlist.c
 * 
 *  Print the chosen word. 
 * 
 *  INPUTS: 
 *      char *word: the word to be printed.
 * 
 *  OUTPUTS:
 *      none
 */
void printWord(char *word) {
    while (*word != '\0') {
        printf("%c", *word);
        ++word;
    }
    printf("\n");
}
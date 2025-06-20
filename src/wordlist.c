#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH(x)  (sizeof(x) / sizeof(x[0]))

/**
 *  getWord
 * 
 *  Returns a word for the game. As a word is used,
 *  the word is replaced by a '0' so this it won't be used
 *  again in subsequent games
 * 
 *  INPUTS: 
 *      NO INPUTS.
 * 
 *  OUTPUTS: 
 *      Returns a word to be used in the hangman game.
 */
char *getWord() {
    char *wordArray[] = {
        "cat", "dog", "train", "elephant", "submarine", "cabinet", "ant", "car"
    };

    srand(time(NULL));
    int randomNumber;
    char *word;

    // Choose a random number and pick an index
    // from the words array.
    randomNumber = rand() % LENGTH(wordArray);
    word = wordArray[randomNumber];

    return word;
}

/**
 *  wordLength
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

    while (*word != '\0') {
        ++count;
        ++word;
    }

    return count;
}

/**
 *  printWord
 * 
 *  Print the chosen word. 
 * 
 *  INPUTS: 
 *      char *word: the word to be printed.
 * 
 *  OUTPUTS:
 *      NO OUTPUTS. 
 */
void printWord(char *word) {
    while (*word != '\0') {
        printf("%c", *word);
        ++word;
    }
    printf("\n");
}

void wasLetterUsed(char usedLetters[]) {
    
}
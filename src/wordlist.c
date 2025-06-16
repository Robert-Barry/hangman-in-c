#include <stdio.h>

// An array of word that can be used for the game
char *words[] = {
    "cat", "train", "elephant", "submarine"
};

// A temporary test word
char *testWord = "dog";

/**
 *  getWord
 * 
 *  Returns a word for the game. 
 * 
 *  INPUTS: 
 *      NO INPUTS.
 * 
 *  OUTPUTS: 
 *      Returns a word to be used in the hangman game.
 */
char *getWord() {
    return testWord;
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


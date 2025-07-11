#include <stdio.h>

/**
 *  welcome
 * 
 *  Text to welcome the player to the game and to
 *  briefly explain how the game works.
 * 
 *  INPUTS:
 *      none
 * 
 *  OUTPUTS:
 *      none
 */
void welcome() {
    printf("Welcome to HANGMAN!\n\n");
    printf("In this simple game, you try to guess the letters\n");
    printf("in a word before the hangman is drawn. If you get\n");
    printf("all the letters in the word you win.\n\n");
}


/** 
 * buildBlanks
 * 
 * Function to build a blank string from the given
 * length of a word.
 * 
 * INPUTS:
 *     char blanks[]: An array to hold the blanks
 *     int length: How many blanks should there be
 * 
 * OUTPUT:
 *     NO RETURN. Uses a reference to an array. 
*/

void buildBlanks(char blanks[], const int length) {
    int i;

    for (i = 0; i < length; ++i) {
        blanks[i] = '_';
    }
}


/**
 *  printUsedLetters
 * 
 *  Prints the letters that the used has already guessed
 *  but were not in the solution.
 * 
 *  INPUTS: 
 *      char usedLetters[]: an array of all the guessed letters
 *      int length: the length of the array
 * 
 *  OUTPUTS: 
 *      NO RETURN.
 * 
 */
void printUsedLetters(char *usedLetters, const char *ptr) {
    // Check if the pointers point to the same location in memory.
    // If they no, no letters have been added to usedLetters.
    // Otherwise, print the letters.
    printf("\nUsed Letters: ");

    if (usedLetters == ptr && usedLetters != NULL) {
        printf("\n");
    } else {

        while (usedLetters != ptr) {
            printf("%c ", *usedLetters);
            ++usedLetters;
        }
        printf("\n");
    }
}

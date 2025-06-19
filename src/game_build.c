#include <stdio.h>

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
    // Otehrwise, print the letters.
    printf("\nUsed Letters: ");

    if (usedLetters == ptr) {
        printf("\n");
    } else {

        while (usedLetters != ptr) {
            printf("%c ", *usedLetters);
            ++usedLetters;
        }
        printf("\n");
    }
}
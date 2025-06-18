#include <stdbool.h>
#include <stdio.h>

/**
 *  addToUsedLetters
 * 
 *  Stores letters used by the user that are not part
 *  of the solution. The function takes a memory location
 *  and a pointer keeping track of the memory to store
 *  letters. If the user had already chosen the
 *  letter previously, the user is told and the funciton
 *  exits. Otherwise, the letter is added to the memory
 *  and the ptr is advanced to the next memory location
 *  and returned. 
 * 
 *  INPUTS: 
 *      char letter: the letter the user tried
 *      char *usedLetters: memory containing the used letters already tried
 *      char * ptr: a memory location where the next used letter will be stored
 * 
 *  OUTPUTS: 
 *      Returns the next location in memory where a used letter
 *      should be stored. 
 * 
 */


char *addUsedLetter(char letter, char *usedLetters, char *ptr) {
    int i;

    // Loop through the memory to see if the letter guessed has
    // already been guessed.
    while (usedLetters != ptr) {
        if (letter == *usedLetters) {
            printf("You've already tried that letter.\n");
            return ptr;
        }
        ++usedLetters;
    }

    // If the letter was not previously guessed, store in the ptr
    // memory location, advance the pointer, and return.
    *ptr = letter;
    ++ptr;

    return ptr;
}

/**
 *  userGuess
 * 
 *  Checks if the letter a user guesses is correct or not. 
 * 
 *  INPUTS: 
 *      char letter: the letter the user guessed
 *      char *word: the word that is being checked
 * 
 *  OUTPUTS: 
 *      Returns true if the user made a correct guess,
 *      false if the guess was incorrect. 
 */
bool userGuess(char letter, char *word) {
    while (*word != '\0') {
        if (*word == letter) {
            return true;
        }
        ++word;
    }
    return false;
}

int addLetter(char letter, char *word, char blanks[], int length, int found) {
    int i;
    int foundLetters = found;

    for (i = 0; i < length; ++i, ++word) {
        if (letter == *word) {
            blanks[i] = letter;
            ++foundLetters;
        }
    }
    printf("FOUND: %i\n", foundLetters);
    return foundLetters;
}

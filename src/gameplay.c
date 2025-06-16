#include <stdbool.h>

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
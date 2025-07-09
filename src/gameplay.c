#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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


char *addUsedLetter(const char letter, char *usedLetters, char *ptr) {
    int i;

    // Loop through the memory to see if the letter guessed has
    // already been guessed.
    while (usedLetters != ptr) {
        if (letter == *usedLetters) {
            printf("You've already guessed that letter.\n");
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
 *  userChoice
 * 
 *  Function that takes a letter guessed by the user. If the letter
 *  is uppercase, make it lowercase. If the guess is not an
 *  alphabetic character, have the user try again. 
 * 
 *  INPUTS: 
 *      NONE
 * 
 *  OUTPUTS: 
 *      Returns the letter chosen by the user converted to lowercase if necessary. 
 */
char userChoice() {
    char letterGuess;
    bool flag = true;

    // Ask the user to choose a letter.
    while (flag) {
        printf("Please guess a letter: ");
        scanf(" %c", &letterGuess);

        // If the letter is uppercase, make it lowercase.
        // If the guess is not aphabetic, try again.
        if (letterGuess >= 'A' && letterGuess <= 'Z') {
            printf("LETTER\n");
            letterGuess = tolower(letterGuess);
            flag = false;
        } else if (letterGuess >= 'a' && letterGuess <= 'z') {
            flag = false;
        } else { 
            printf("Your guess was invalid.\n");
            printf("Please enter only letters for the guess.\n\n");
        }
    }
    printf("You guessed %c\n", letterGuess);

    return letterGuess;
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
bool userGuess(const char letter, const char *word) {
    while (*word != '\0') {
        if (*word == letter) {
            return true;
        }
        ++word;
    }
    return false;
}

/**
 *  addLetter
 * 
 *  adds a letter to the user's blanks when they make a correct letter guess
 * 
 *  INPUTS: 
 *      char letter: the letter to add to the blanks array
 *      char *word: the word that contains the correct letter guess
 *      char blanks[]: the blank spaces shown to the user, including correct letters
 *      int length: the length of the word
 *      int found: keep track of how many letters were found
 * 
 *  OUTPUTS: 
 *      Returns an int representing the number of correct letters that matched in the
 *      given word the player is trying to guess.
 */
int addLetter(const char letter, const char *word, char blanks[], const int length, const int found) {
    int i;
    int foundLetters = found;
    
    // Loop through each letter in the given word to see how many letters match
    // the player's chosen letter.
    for (i = 0; i < length; ++i, ++word) {
        if (letter == *word) {
            blanks[i] = letter;
            ++foundLetters;
        }
    }

    // Return how many letters were found in the word.
    return foundLetters;
}

/**
 *  playAgain
 * 
 *  Ask the player if they want to play another game or quit. 
 * 
 *  INPUTS: 
 *      NONE. 
 * 
 *  OUTPUTS: 
 *      Returns true if the player wants to play again. 
 */
bool playAgain(char *usedLetters) {
    char playAgain;
    bool choice;       // True if the player wants to play again
    bool flag = true;  // Loop if the user gives a bad answer

    printf("Would you like to play again? (y/n): ");
    scanf(" %c", &playAgain);

    do {
        if (playAgain == 'Y' || playAgain == 'y') {
            choice = true;
            flag = false;
        } else if (playAgain == 'N' || playAgain == 'n') {
            choice = false;
            flag = false;
            free(usedLetters);
        } else {
            printf("Please enter only 'y' or 'n'.\n");
            flag = true;
        }
    } while (flag);

    return choice;
}

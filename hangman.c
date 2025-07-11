/*
    Hangman is a simple game where a player is given
    the chance to guess a letter of a word. If the player
    completes the word, they win the game. If the player
    gets a letter wrong, the begin to draw the "hangman",
    a representation of a man being hanged. If the picture
    is finished before the user guesses the word, the
    user loses the game.

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "include/wordlist.h"
#include "include/game_state.h"
#include "include/hang_image.h"
#include "include/game_build.h"
#include "include/gameplay.h"

#define NUMBER_OF_LETTERS  25


int main(void) {
    // Variables
    char *word;          // The word to be guessed
    char letterGuess;    // The letter the player chooses to guess
    bool guess;          // True if the player gives a correct letter guess
    bool again = true;   // True when the player wants to play again
    bool gameInPlay;     // True if a game is in progress
    int i;               // For keeping track in loops
    int foundLetters;    // The number of letters a player has successfully guessed
    State gameState;     // An enum to track the state if the game using the scaffold

    // The following could have easily been done with arrays, but this was an
    // experiment in dynamic memory allocation.

    // Create a location in memory to hold 26 incorrectly guessed letters.
    char *usedLetters = (char *) malloc(NUMBER_OF_LETTERS * sizeof(char));
    // ptr tracks where the next wrong guess will be stored in memory.
    char *ptr = usedLetters;

    // Create a location in memory to store 26 correctly guessed letters
    char *goodLetters = (char *) malloc(NUMBER_OF_LETTERS * sizeof(char));
    // goodPtr tracks where the next correct guess will be stored in memory.
    char *goodPtr = goodLetters;

    // Check that the memory was created.
    if (usedLetters == NULL || goodLetters == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    // Text that welcomes the player to the game.
    welcome();

    // The outer playAgain loop sets-up and plays through a single
    // game of Hangman.
    while (again == true) {
        // Set the state of the game to the beginning
        foundLetters = 0;
        gameState = empty;
        gameInPlay = true;

        // Get the new word & its length to use in the game
        word = getWord();
        int length = wordLength(word);

        // Create the blank spaces to be shown to the player
        char blanks[length];
        buildBlanks(blanks, length);

        printf("The word you are guessing has %i letters.\n\n", length);

        // Draw an empty hangman scaffold at the start of the game
        scaffold(empty);
        
        // Create a game loop to play a single game of hangman
        while(gameInPlay == true) {
            
            printBlanks(blanks, length);
            
            printUsedLetters(usedLetters, ptr);

            printf("\n\n");
            
            // Have the player choose a letter
            letterGuess = userChoice();
            
            // True if the user gave a correct letter
            guess = userGuess(letterGuess, word);
            
            if (guess == true) {
                // Create a temporary pointer to compare the returned goodPtr
                char *tempPtr = goodPtr;
                // Add a letter to the goodLetters array if it hasn't been used before
                goodPtr = addUsedLetter(letterGuess, goodLetters, goodPtr);
                
                // If goodPtr has changed then add the letter to the blanks
                if (goodPtr != tempPtr) {
                    // foundletters tracks if the numebr of letters found matches the length
                    // of the word being guessed. If it does, all the letters have been found
                    // and the game has been won.
                    foundLetters = addLetter(letterGuess, word, blanks, length, foundLetters);
                }
                
                if (foundLetters == length) {
                    // The game has been won.
                    // Show the uncompleted scaffold and the word that was guessed.
                    scaffold(gameState);
                    printBlanks(blanks, length);

                    printf("\n\n******\n\nYOU WIN\n\n******\n\n");

                    // As the player if they want to play another game.
                    again = playAgain(usedLetters);

                    // Reset the ptr to point to the start of usedLetters
                    // and goodPtr to point to the start of goodLetters
                    if (again) {
                        ptr = usedLetters;
                        goodPtr = goodLetters;
                    }
                    gameInPlay = false;
                    break;
                }
            } else {
                printf("The guess is incorrect.\n");
                ptr = addUsedLetter(letterGuess, usedLetters, ptr);
                ++gameState;
                if (gameState == complete) {
                    // The game has been lost.
                    // Print the completed scaffold.
                    scaffold(gameState);
                    
                    printf("\n\n******\n\nYOU LOSE\n\n******\n\n");
                    again = playAgain(usedLetters);
                    // Reset the ptr to point to the start of usedLetters
                    // and goodPtr to point to the start of goodLetters
                    if (again) {
                        ptr = usedLetters;
                        goodPtr = goodLetters;
                    }
                    gameInPlay = false;
                    break;
                }
            }
            scaffold(gameState);
        }
    }

    return 0;
}
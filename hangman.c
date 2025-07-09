/*
    Hangman is a simple game where a player is given
    the chance to guess a letter of a word. If the player
    completes the word, they win the game. If the player
    gets a letter wrong, the begin to draw the "hangman",
    a representation of a man being hanged. If the picture
    is finished before the user guesses the word, the
    user loses the game.

    TO-DO:
        - Fix an issue where play again enters an infinite loop on an invalid selection
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
    char *word;
    char letterGuess; 
    bool guess;
    bool again = true;
    bool gameInPlay;
    int i;
    int foundLetters;
    State gameState;

    // Create a location in memory to hold 26 incorrect guessed letters.
    char *usedLetters = (char *) malloc(NUMBER_OF_LETTERS * sizeof(char));
    // ptr tracks where the next wrong guess will be stored in memory.
    char *ptr = usedLetters;

    // Create a location in memory to store 26 correct guessed letters
    char *goodLetters = (char *) malloc(NUMBER_OF_LETTERS * sizeof(char));
    // goodPtr tracks where the next correct letter will be stored in memory.
    char *goodPtr = goodLetters;

    // Check that the memory was created.
    if (usedLetters == NULL || goodLetters == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    printf("Welcome to HANGMAN!\n\n");
    printf("In this simple game, you try to guess the letters\n");
    printf("in a word before the hangman is drawn. If you get\n");
    printf("all the letters in the word you win.\n\n");

    // The outer playAgain loop plays sets-up and plays through a single
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
            
            // Print the blanks
            for (i = 0; i < length; ++i) {
                printf("%c ", blanks[i]);
            }
            printf("\n");
            
            printUsedLetters(usedLetters, ptr);

            printf("\n\n");
            
            // Have the player choose a letter
            letterGuess = userChoice();
            
            // True if the user gave a correct letter
            guess = userGuess(letterGuess, word);
            
            /** TODO: Refactor this code */
            if (guess == true) {
                // Create a temporary pointer to compare the returned goodPtr
                char *tempPtr = goodPtr;
                // Add a letter to the goodLetters array if it hasn't been used before
                goodPtr = addUsedLetter(letterGuess, goodLetters, goodPtr);
                
                // If goodPtr has changed then add the letter to the blanks
                if (goodPtr != tempPtr) {
                    foundLetters = addLetter(letterGuess, word, blanks, length, foundLetters);
                }

                if (foundLetters == length) {
                    scaffold(gameState);
                    for (i = 0; i < length; ++i) {
                        printf("%c ", blanks[i]);
                    }
                    printf("\n");
                    printf("\n\n******\n\nYOU WIN\n\n******\n\n");
                    //printf("The word was %s\n\n", word);
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
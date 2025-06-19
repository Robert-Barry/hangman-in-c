/*
    Hangman is a simple game where a player is given
    the chance to guess a letter of a word. If the player
    completes the word, they win the game. If the player
    gets a letter wrong, the begin to draw the "hangman",
    a representation of a man being hanged. If the picture
    is finished before the user guesses the word, the
    user loses the game.

    TO-DO:
        - Choose a random word from the word list
        - Track which words have already been used in previous games
        - Put all the state in a single struct: again, gameInPlay, foundLetters, scaffoldState
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

    // Create a location in memory to hold 26 letters.
    char *usedLetters = (char *) malloc(NUMBER_OF_LETTERS * sizeof(char));
    // ptr tracks where the next wrong guess will be stored in memory.
    char *ptr = usedLetters;

    // Check that the memory was created.
    if (usedLetters == NULL) {
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
                foundLetters = addLetter(letterGuess, word, blanks, length, foundLetters);

                if (foundLetters == length) {
                    printf("\n\n******\n\nYOU WIN\n\n******\n\n");
                    again = playAgain();
                    gameInPlay = false;
                    break;
                }
            } else {
                printf("The guess is incorrect.\n");
                ptr = addUsedLetter(letterGuess, usedLetters, ptr);
                ++gameState;
                if (gameState == complete) {
                    printf("\n\n******\n\nYOU LOSE\n\n******\n\n");
                    again = playAgain();
                    gameInPlay = false;
                    break;
                }
            }
            scaffold(gameState);
        }
    }

    return 0;
}
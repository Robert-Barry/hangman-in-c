/*
    Hangman is a simple game where a player is given
    the chance to guess a letter of a word. If the player
    completes the word, they win the game. If the player
    gets a letter wrong, the begin to draw the "hangman",
    a representation of a man being hanged. If the picture
    is finished before the user guesses the word, the
    user loses the game.

    TO-DO:
        - Come up with a word list ^^
        - Come up with an ASCII drawing of a "hangman" ^^
        - reprsent a word with blank spaces ^^^
        - let the user guess a letter ^^^
        - if the letter is in the word, replace the 
          appropriate blank space with the letter
        - if the letter is not in the word, draw
          a piece of the hangman
        - If the user guesses the word before the
          hangman is drawn, the user wins 
        - If the hangman is drawn before the user
          guesses the word, the user loses
        - End the game
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

#define LENGTH(x)  sizeof(x) / sizeof(x[0])
#define NUMBER_OF_LETTERS  25


int main(void) {
    // Variables
    char *word;
    char letterGuess; 
    bool guess;
    bool playAgain = true;
    bool gameInPlay = true;
    int i;
    int foundLetters = 0;
    State gameState = 0;

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
    while (playAgain == true) {
        // Get the new word & its length to use in the game
        word = getWord();
        int length = wordLength(word);

        // Create the blank spaces to be shown to the player
        char blanks[length];
        buildBlanks(blanks, length);

        printf("The word you are guessing has %i letters.\n\n", length);

        // Draw an empty hangman scaffold at the start of the game
        scaffold(empty);
        
        while(gameInPlay == true) {

            
            
            for (i = 0; i < length; ++i) {
                printf("%c ", blanks[i]);
            }
            printf("\n");

            printUsedLetters(usedLetters, ptr);

            printf("\n\n");

            printf("Please guess a letter: ");
            scanf(" %c", &letterGuess);
            printf("You guessed %c\n", letterGuess);

            guess = userGuess(letterGuess, word);
            
            

            if (guess == true) {
                foundLetters = addLetter(letterGuess, word, blanks, length, foundLetters);
                printf("FOUND: %i, LENGTH: %i\n", foundLetters, length);
                if (foundLetters == length) {
                    printf("\n\n***\nWIN\n***\n\n");
                }
            } else {
                printf("The guess is incorrect.\n");
                ptr = addUsedLetter(letterGuess, usedLetters, ptr);
                ++gameState;
                if (gameState == complete) {
                    printf("\n\n***\nLOSE\n***\n\n");
                }
            }
            scaffold(gameState);
        }
    }

    return 0;
}
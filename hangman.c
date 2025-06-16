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


int main(void) {
    // Variables
    char *word;
    char letterGuess;
    bool guess;
    bool playAgain = true;
    char *guessedLetters = NULL;
    int size = 0;
    int capacity = 0;
    bool gameInPlay = true;
    int i;
    

    printf("Welcome to HANGMAN!\n\n");
    printf("In this simple game, you try to guess the letters\n");
    printf("in a word before the hangman is drawn. If you get\n");
    printf("all the letters in the word you win.\n\n");

    while (playAgain == true) {
        word = getWord();
        int length = wordLength(word);

        char blanks[length];
        buildBlanks(blanks, length);

        printf("The word you are guessing has %i letters.\n\n", length);
        
        while(gameInPlay == true) {

            scaffold(empty);
            
            for (i = 0; i < length; ++i) {
                printf("%c ", blanks[i]);
            }

            printf("\n\n");

            printf("Please guess a letter: ");
            scanf(" %c", &letterGuess);
            printf("You guessed %c\n", letterGuess);

            guess = userGuess(letterGuess, word);

            if (guess == true) {
                printf("The guess is correct.\n");
            } else {
                printf("The guess is incorrect.\n");
            }
        }
    }

    return 0;
}
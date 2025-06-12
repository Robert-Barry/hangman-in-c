/*
    Hangman is a simple game where a player is given
    the chance to guess a letter of a word. If the player
    completes the word, they win the game. If the player
    gets a letter wrong, the begin to draw the "hangman",
    a representation of a man being hanged. If the picture
    is finished before the user guesses the word, the
    user loses the game.

    TO-DO:
        - Come up with a word list
        - Come up with an ASCII drawing of a "hangman"
        - reprsent a word with blank spaces
        - let the user guess a letter
        - if the letter is in the word, replace the 
          appropriate blank space with the letter
        - if the letter is not in the word, draw
          a piece of the hangman
        - End the game
*/

#include <stdio.h>
#include "include/wordlist.h"

int main(void) {
    printf("%s\n", getWord());

    return 0;
}
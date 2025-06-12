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
        - Come up with an ASCII drawing of a "hangman"
        - reprsent a word with blank spaces
        - let the user guess a letter
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
#include "include/wordlist.h"

void buildBlanks(char *word, char *blanks) {

    while (*word != '\0') {
        *blanks = '_';
        ++word;
        ++blanks;
    }
    //++blanks;
    *blanks = '\0';
}

int main(void) {
    char *word = getWord();
    char *blanks;

    buildBlanks(word, blanks);

    while (*blanks != '\0') {
      printf("%c ", *blanks);
      ++blanks;
    }

    printf("\n");

    return 0;
}
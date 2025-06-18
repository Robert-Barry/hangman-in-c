#ifndef GAMEPLAY_H
#define GAMEPLAY_H

bool userGuess(char letter, char *word);
char *addUsedLetter(char letter, char *usedLetters, char *ptr);
int addLetter(char letter, char *word, char blanks[], int length, int found);
bool playAgain();

#endif
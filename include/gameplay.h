#ifndef GAMEPLAY_H
#define GAMEPLAY_H

bool userGuess(const char letter, const char *word);
char *addUsedLetter(const char letter, char *usedLetters, char *ptr);
int addLetter(const char letter, const char *word, char blanks[], const int length, const int found);
bool playAgain();
char userChoice();

#endif
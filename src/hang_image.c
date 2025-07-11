#include <stdio.h>
#include "../include/game_state.h"

/**
 *  topScaffold
 *  hang_image.c
 * 
 *  Draws the top of the scaffold for Hangman
 * 
 */
void topScaffold() {
    printf("   ______\n");
    printf("  |      |\n");
}

/**
 *  bottomScaffold
 *  hang_image.c
 * 
 *  Draws the bottom of the scaffold for Hangman
 * 
 */
void bottomScaffold() {
    printf("  |\n");
    printf(" ----\n");
}

/**
 *  completeScaffold
 *  hang_image.c
 * 
 *  Draws the complete scaffold.
 * 
 */
void completeScaffold() {
    void topScaffold();
    void bottomScaffold();

    topScaffold();
    printf("  |      O\n");
    printf("  |     /|\\\n");
    printf("  |     / \\\n");
    bottomScaffold();
}

/**
 *  emptyScaffold
 *  hang_image.c
 * 
 *  Draws a scaffold without the man
 * 
 */
void emptyScaffold() {
    void topScaffold();
    void bottomScaffold();

    topScaffold();
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    bottomScaffold();
}

/**
 *  scaffold
 *  hang_image.c
 * 
 *  Determines which scaffold to draw to the screen.
 * 
 *  INPUTS:
 *      const State state: The current state of the game
 * 
 */
void scaffold(const State state) {
    void topScaffold();
    void bottomScaffold();
    void completeScaffold();
    void emptyScaffold();

    switch(state) {
        case empty:
            emptyScaffold();
            break;
        case head:
            topScaffold();
            printf("  |      O\n");
            printf("  |\n");
            printf("  |\n");
            bottomScaffold();
            break;
        case arm1:
            topScaffold();
            printf("  |      O\n");
            printf("  |     /\n");
            printf("  |\n");
            bottomScaffold();
            break;
        case arm2:
            topScaffold();
            printf("  |      O\n");
            printf("  |     / \\\n");
            printf("  |\n");
            bottomScaffold();
            break;
        case body:
            topScaffold();
            printf("  |      O\n");
            printf("  |     /|\\\n");
            printf("  |\n");
            bottomScaffold();
            break;
        case leg1:
            topScaffold();
            printf("  |      O\n");
            printf("  |     /|\\\n");
            printf("  |     /\n");
            bottomScaffold();
            break;
        case complete:
            completeScaffold();
            break;
        default:
            emptyScaffold();
            break;     
    }
}
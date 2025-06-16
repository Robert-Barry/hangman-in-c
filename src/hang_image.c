#include <stdio.h>
#include "../include/game_state.h"

/**
 *  topScaffold
 * 
 *  Convenience function.
 *  Draws the top of the scaffold for Hangman
 * 
 */
void topScaffold() {
    printf("   ______\n");
    printf("  |      |\n");
}

/**
 *  bottomScaffold
 * 
 *  Convenience function.
 *  Draws the bottom of the scaffold for Hangman
 * 
 */
void bottomScaffold() {
    printf("  |\n");
    printf(" ----\n");
}

/**
 *  completeScaffold
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
 * 
 *  Determines which scaffold to draw to the screen.
 * 
 */
void scaffold(State state) {
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
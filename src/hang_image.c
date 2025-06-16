#include <stdio.h>
#include "../include/game_state.h"

void topScaffold() {
    printf("   ______\n");
    printf("  |      |\n");
}

void bottomScaffold() {
    printf("  |\n");
    printf(" ----\n");
}

void completeScaffold() {
    void topScaffold();
    void bottomScaffold();

    topScaffold();
    printf("  |      O\n");
    printf("  |     /|\\\n");
    printf("  |     / \\\n");
    bottomScaffold();
}

void emptyScaffold() {
    void topScaffold();
    void bottomScaffold();

    topScaffold();
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    bottomScaffold();
}

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
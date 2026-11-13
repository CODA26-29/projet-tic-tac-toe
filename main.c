#include <stdio.h>
#include <stdlib.h>
#include "tic-tac-toe.h"

int main() {
    system("clear");
    char **grid = initGrid();
    int playing = 1;

    while (playing == 1) {
        playerTurn(grid);
        displayGrid(grid);
        opponentTurn(grid);
        displayGrid(grid);
    }



    int i = 0;

    while (grid[i] != NULL) {
        free(grid[i]);
        i = i + 1;
    }

    free(grid);
    return 0;
}

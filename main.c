#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tic-tac-toe.h"

int main() {
    char **grid = initGrid();
    int end = 0;

    clearTerminal();
    displayGrid(grid);
    while (end == 0) {
        playerTurn(grid);

        clearTerminal();

        displayGrid(grid);
        sleep(2);

        end = isWinner(grid, 'X');
        if (end == 1) {
            printf("Gagné !\n");
            break;
        }
        end = isNull(grid);
        if (end == 1) {
            printf("Null !\n");
            break;
        }

        clearTerminal();

        opponentTurn(grid);
        displayGrid(grid);
        end = isWinner(grid, 'O');

        if (end == 1) {
            printf("PERDU...\n");
            break;
        }

        end = isNull(grid);
        if (end == 1) {
            printf("Null !\n");
        }
    }

    freeAndExit(grid);
    return 0;
}

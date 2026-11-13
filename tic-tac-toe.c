#include <stdlib.h>
#include <stdio.h>

char ** initGrid() {
    char ** grid =malloc(4 * sizeof(*grid));
    grid[3] = NULL;

    grid[0] = malloc(4 * sizeof(char));
    grid[1] = malloc(4 * sizeof(char));
    grid[2] = malloc(4 * sizeof(char));

    return grid;
}

void freeAndExit(char ** grid) {
    int i = 0;

    while (grid[i] != NULL) {
        free(grid[i]);
        i = i + 1;
    }

    free(grid);
    exit(0);
}

void clearTerminal() {
    int cleared = system("clear");
    if (cleared == 1) printf("Erreur impossible de clear.");
}

void displayGrid(char **tab) {
    //system("clear");
    int c1 = 0;
    while (tab[c1] != NULL) {
        int c2 = 0;

        if (c1 > 0) {
            printf("---------\n");
        }

        while (c2 < 3) {
            if (c2 > 0) {
                printf(" | ");
            }
            if (tab[c1][c2] != '\0') {
                printf("%c", tab[c1][c2]);
            } else {
                printf(" ");
            }
            c2++;
        }
        printf("\n");
        c1++;
    }
    printf("\n");
}

int caseTaken(char ** grid, int pos) {
    if (pos < 9) {
        int line = pos / 3;
        int col = pos % 3;
        return grid[line][col] != '\0';
    }
    return 1;
}

void attributeValue(char ** grid, int pos, char sign) {
    int line = pos / 3;
    int col = pos % 3;
    grid[line][col] = sign;
}

void playerTurn(char ** grid) {
    int selected = -1;
    printf("Ou voulez vous jouer ? \n");
    if (scanf("%d", &selected) != 1) {
        printf("Invalide. \n");
        freeAndExit(grid);
    }
    if (selected < 0 || selected > 8) {
        printf("Invalide. \n");
        freeAndExit(grid);
    }
    if (caseTaken(grid, selected)) {
        printf("Case prise. \n");
        freeAndExit(grid);
    }
    attributeValue(grid, selected, 'X');
}

void opponentTurn(char ** grid) {
    int pos = 0;

    while (caseTaken(grid, pos) && pos < 10) {
        pos++;
    }

    if (pos == 10) return;

    attributeValue(grid, pos, 'O');
}

int isWinner(char ** grid, char sign) {
    if (grid[0][0] == sign && grid[0][1] == sign && grid[0][2] == sign) {
        return 1;
    }
    if (grid[1][0] == sign && grid[1][1] == sign && grid[1][2] == sign) {
        return 1;
    }
    if (grid[2][0] == sign && grid[2][1] == sign && grid[2][2] == sign) {
        return 1;
    }

    if (grid[0][0] == sign && grid[1][0] == sign && grid[2][0] == sign) {
        return 1;
    }
    if (grid[0][1] == sign && grid[1][1] == sign && grid[2][1] == sign) {
        return 1;
    }
    if (grid[0][2] == sign && grid[1][2] == sign && grid[2][2] == sign) {
        return 1;
    }

    if (grid[0][0] == sign && grid[1][1] == sign && grid[2][2] == sign) {
        return 1;
    }
    if (grid[0][2] == sign && grid[1][1] == sign && grid[2][0] == sign) {
        return 1;
    }

    return 0;
}

int isNull(char ** grid) {
    int pos = 0;

    while (caseTaken(grid, pos) && pos < 10) {
        pos++;
    }

    if (pos == 10) return 1;
    return 0;
}
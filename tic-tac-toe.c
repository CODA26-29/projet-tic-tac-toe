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
    if (pos < 3) {
        return grid[0][pos] == 'O' || grid[0][pos] == 'X';
    }
    if (pos < 6) {
        return grid[1][pos - 3] == 'O' || grid[1][pos - 3] == 'X';
    }
    if (pos < 9) {
        return grid[2][pos - 6] == 'O' || grid[2][pos - 6] == 'X';
    }
    return 1;
}

void attributeValue(char ** grid, int pos, char sign) {
    if (pos < 3) {
        grid[0][pos] = sign;
    } else if (pos < 6) {
        grid[1][pos - 3] = sign;
    } else if (pos < 9) {
        grid[2][pos - 6] = sign;
    }
}

void playerTurn(char ** grid) {
    int selected = -1;
    printf("Ou voulez vous jouer ? \n");
    if (scanf("%d", &selected) != 1) {
        exit(0);
    }
    printf("%d\n", caseTaken(grid, selected));
    attributeValue(grid, selected, 'X');
}

void opponentTurn(char ** grid) {
    char selected = '0';
    int pos = 0;

    while (selected == 'O' || selected == 'X') {
        pos++;
        if (pos < 3) {
            selected = grid[0][pos];
        } else if (pos < 6) {
            selected = grid[1][pos - 3];
        } else if (pos < 9) {
            selected = grid[2][pos - 6];
        } else {
        }
    }

    attributeValue(grid, pos, 'O');
}
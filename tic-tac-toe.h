#ifndef _TIC_TAC_TOE_
#define  _TIC_TAC_TOE_

char ** initGrid();
void displayGrid(char **tab);
void playerTurn(char ** grid);
void opponentTurn(char ** grid);
int isWinner(char ** grid, char sign);
int isNull(char ** grid);
void freeAndExit(char ** grid);
void clearTerminal();

#endif

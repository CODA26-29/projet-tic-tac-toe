# Tic-Tac-Toe

Play a round of tic-tac-toe against the computer in your terminal.

## Overview

Tic-Tac-Toe is a single-player command-line game written in C. You play as `X` and move first. The computer plays as `O` on a 3 × 3 board.

## Features

- Text-based board that refreshes after each move.
- Computer opponent that fills the first available cell, scanning from position `0` to `8`.
- Win detection across all rows, columns, and diagonals, plus draw detection when the board fills up.
- French prompts and result messages.

## Installation

Use a Unix-like terminal with Git, `make`, and a C compiler available as `gcc`.

```sh
git clone https://github.com/CODA26-29/projet-tic-tac-toe.git
cd projet-tic-tac-toe
make re
./tic-tac-toe
```

The repository includes a prebuilt `tic-tac-toe` executable. `make re` removes that copy and builds an executable for your machine. The default `make` target rebuilds when a C source file is newer than the executable. Use `make fclean` to remove the executable, or `make re` after editing the header to force a rebuild.

## How to play?

1. At the prompt, enter an integer from `0` to `8` and press Enter. Positions run left to right, starting at the top row.

   | Row | Left | Center | Right |
      | --- | --- | --- | --- |
   | Top | 0 | 1 | 2 |
   | Middle | 3 | 4 | 5 |
   | Bottom | 6 | 7 | 8 |

2. The game places your `X` and pauses for two seconds. If the round continues, the computer places an `O`.
3. Get three marks in a row, column, or diagonal to win. The game prints `Gagné !` for a win, `PERDU...` for a loss, or `Null !` for a draw.
4. Run `./tic-tac-toe` again to start a new round.

A nonnumeric entry or an integer outside the supported range prints `Invalide.` and exits. Selecting an occupied cell prints `Case prise.` and exits.

## Tech Stack

- **C** for the board, input, and game logic.
- **Make and GCC** for building the executable with `-Wall -Wextra -O2`.

| File | Purpose |
| --- | --- |
| `main.c` | Runs the turn loop, checks the result after each move, and displays the outcome. |
| `tic-tac-toe.c` | Allocates and frees the board, displays cells, handles both turns, and checks for wins and draws. Positions are converted to a row with integer division by 3 and to a column with the remainder. |
| `tic-tac-toe.h` | Declares the game functions used by `main.c`. |
| `Makefile` | Defines the build, clean, and rebuild targets. |
| `tic-tac-toe` | Prebuilt executable tracked in the repository. |

## Dependencies

The game uses the C standard library for terminal I/O and memory allocation, POSIX `sleep()` for the pause between turns, and the external `clear` command to refresh the terminal. The build requires no third-party libraries.

---

[@rapphcd](https://github.com/rapphcd)

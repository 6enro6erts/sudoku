/*
 * grid.h - a header for grid.c
 *
 * a grid is a 9x9 grid that is used to store the values for a sudoku puzzle
 * C-median Dartmouth CS50 20S
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Makes a 2D grid of integers, and returns this value. The user must free the grid or call gridDelete.
 *
 */
int **gridNew(void);

/*
 * Sets the value of the grid at a certain point. Does nothing if the grid pointer is null.
 *
 */
void gridSet(int **grid, int row, int col, int value);

/*
 * Gets the value of the grid at a certain point. Returns -1 if the grid pointer is null
 *
 */
int gridGet(int **grid, int row, int col);

/*
 * Frees each of the rows in the grid and the grid itself
 *
 */
void gridDelete(int **grid);

/*
 * Prints the grid to stdout
 *
 */
void gridPrint(int **grid);

bool gridCopy(int **grid);

void gridEmpty(int **grid);

bool checkValue(int **grid, int i, int j, int value); 

void gridFill(int **grid);

bool randFill(int **grid, int i, int j, int count);

void gridTransfer(int **grid1, int **grid2);

int fiftyFifty();

int randNine();

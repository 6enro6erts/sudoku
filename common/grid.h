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

/* 
 * solver.h - a header for solver.c


 * solver contains the functions necessary to solve a sudoku grid
 * C-median Dartmouth CS50 20S
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grid.h"
#include "node.h"
#include "shared.h"
#include <unistd.h>

/******************* solve *****************/
/*takes a grid and a value that says whether or not to print
RETURN:
* True on only one solution
* False on no or multiple solutions*/
bool solve(int **grid, bool print);


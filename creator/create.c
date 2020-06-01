/*
 * create.c - implementation of the create module
 *
 * C-median Dartmouth CS50 20S
 */

#include <stdio.h>
#include <stdlib.h> 
#include "grid.h"
#include "shared.h"


/***************** create **********************/
void create(int** grid){
	gridFill(grid); 
	createDFS(grid);
}

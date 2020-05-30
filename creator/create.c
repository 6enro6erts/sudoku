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
void create(void){
    int** grid; 
    grid = gridNew();  
    gridFill(grid); 
    gridPrint(grid); 
    gridDelete(grid);
}
/* 
 * shared.h - a header for shared.c
 *
 * 
 * shared stores functions used by solve and create, mostly validating aspects of the grid
 * C-median Dartmouth CS50 20S
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grid.h"
#include "node.h"


/**************** checkNode ****************/
/*checks that a note is correctly placed:
return
True - there are no conflicts 
False - there is an error with the placement

Note: zeros are IGNORED, so a blank grid with one node will return true
*/
bool checkNode(node_t *node, int **grid);

/************************** gimme **************/
/*checks to see if the given node has only one valid solution
return:
true: yes a gimme, value is set to correct value
false: not a gimme*/
int gimme(node_t *node,int **grid);
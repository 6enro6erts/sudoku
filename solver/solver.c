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

/******************* solve *****************/
/*takes a grid and a value that says whether or not to print*/
void solve(int **grid, bool print){
    node_t *testnode = nodeNew(8,4,9);
    if(checkNode(testnode,grid)){
        printf("valid node!\n");
    }
    else printf("invalid node!\n");
    
    if(gimme(testnode,grid)){
        printf("gimme!\n");
    }
    else printf("not a gimme!\n");
    nodeDelete(testnode);
    //deleteGrid(grid);
}

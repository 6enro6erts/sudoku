/*
 * create.c - implementation of the create module
 *
 * C-median Dartmouth CS50 20S
 */

#include <stdio.h>
#include <stdlib.h> 
#include "grid.h"
#include "shared.h"
#include "bag.h"
#include "node.h"
#include "solve.h"
#include <unistd.h>


/***************** create **********************/
void create(int** grid){
	gridEmpty(grid);
	solve(grid,false);
    bag_t *stack = bag_new(); //create a bag to stack possibilities 
    //bag_t *backtrace = bag_new(); //create a bag for backtracing 
    int zcount = 0;
    node_t *currentNode; //create the current and next nodes
    currentNode = getRandomNode(grid); //start at random node
    grid[nodeGetRow(currentNode)][nodeGetColumn(currentNode)] = 0;
    zcount++;
    bag_insert(stack,currentNode);

    while(zcount<45){ 
        currentNode = getRandomNode(grid);
        grid[nodeGetRow(currentNode)][nodeGetColumn(currentNode)] = 0;
        zcount++;
		int **solveGrid = gridNew();
		gridTransfer(solveGrid, grid);
        if(solve(solveGrid,false)!=1){
            grid[nodeGetRow(currentNode)][nodeGetColumn(currentNode)] = nodeGetValue(currentNode);
            zcount--;
			//add to hashtable 
        }
		gridDelete(solveGrid);
        bag_insert(stack,currentNode);
		//check hashtable size doesnt match numzeros 
		//check we havent tried literally every option
		//if we have, reset current node, free hashtabel, step back 1 more rinse and repeat
    }

    bag_delete(stack,nodeDelete); //clear bags
}

#ifdef MYTEST
int main(int argc, char *argv[]){
        // print the command line so the user can view what was called on the solver
        for (int n = 0; n < argc; n++){
                fprintf(stdout, " %s ", argv[n]);
        }
        fprintf(stdout, "\n");

        if (argc != 2 || strcmp(argv[1], "create")){
                fprintf(stderr,"Incorrect number of arguments\nUsage: ./sudoku command. \nSee readme for more\n");
                return 1;
        }

        /*// initialize grid and record an error if gridNew returns null
        int **grid = gridNew();
        if (grid == NULL)
                fprintf(stderr, "gridNew returned a null value.\n");

        // call gridcopy, and print the resulting grid
        gridCopy(grid);
        fprintf(stdout, "gridCopy was called, printing the grid that was entered as input:\n");
        gridPrint(grid);

        // test the gridSolver
        printf("calling solve(grid, true)\n");
        int numSol = solve(grid, true);
        printf("number of solutions is: %d\n",numSol);

        // test gridDelete
        gridDelete(grid);
        fprintf(stdout, "gridDelete was called\n");

        fprintf(stdout, "End of this unit test\n\n");
        fprintf(stdout, "---------------------------------------------\n");
        */return 0;
}

#endif

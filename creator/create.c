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
#ifdef MYTEST
	fprintf(stdout, "Printing the solved grid that we will remove values from to make our puzzle.\n");
	gridPrint(grid);
#endif
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
#include <time.h>
int main(int argc, char *argv[]){
        // print the command line so the user can view what was called on the solver
        for (int n = 0; n < argc; n++){
                fprintf(stdout, " %s ", argv[n]);
        }
        fprintf(stdout, "\n");

	// log error and return 1 if there was an incorrect number of args
        if (argc != 1){
                fprintf(stderr,"Incorrect number of arguments\nUsage: ./createTest. \nSee readme for more\n");
                return 1;
        }

	// seed the random number generator
	fprintf(stdout, "seeding the random number generator\n");
	srand(time(NULL));

	// create an empty grid
	int **grid = gridNew();
	if (grid==NULL)
		fprintf(stderr, "gridNew returned a null grid!\n");

	// create the grid
	fprintf(stdout, "calling create(grid)\n");
	create(grid);

	// print the grid created
	fprintf(stdout, "Printing the resulting grid:\n");
	gridPrint(grid);

	// delete grid
	fprintf(stdout, "Deleting the grid...\n");
	gridDelete(grid);


        fprintf(stdout, "End of this unit test\n\n");
        fprintf(stdout, "---------------------------------------------\n");
        return 0;
}

#endif

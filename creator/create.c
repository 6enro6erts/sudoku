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

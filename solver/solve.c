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
#include "bag.h"
#include <unistd.h>

/******************* solve *****************/
/*takes a grid and a value that says whether or not to print
* return number of solutions 
*/
int solve(int **grid, bool print){
    gimmeScanner(grid); //fill in all gimmes (only one possible value)
    
    int solcount = 0; //track number of solutions 
    bag_t *stack = bag_new(); //create a bag to stack possibilities 
    bag_t *backtrace = bag_new(); //create a bag for backtracing 

    node_t *currentNode,*nextNode,*btNode; //create the current and next nodes
    currentNode = getNextNode(grid); //start at the first node of the grid
    pushGuesses(currentNode,grid,stack); //stack all possible solutions for first node
    nodeDelete(currentNode); //delete the first node 
    currentNode = bag_extract(stack); //pull the first item from the stack
    //insert a copy of the item into the backtrace so we have a "root" for the backtrace stack
    if(currentNode!=NULL) bag_insert(backtrace,nodeNew(nodeGetRow(currentNode),nodeGetColumn(currentNode),0));

    while(currentNode!=NULL){ //while there are untried possibilites
        grid[nodeGetRow(currentNode)][nodeGetColumn(currentNode)] = nodeGetValue(currentNode); //set the grid to that possiblity
        nextNode = getNextNode(grid); //get next unsolved node in the grid
        if(nextNode!=NULL){ //if there is a next node
            if(pushGuesses(nextNode,grid,stack)){ //push all possibilites for that node to the stack
                bag_insert(backtrace,nextNode); //push the node onto the backtrace
            } 
            else{
            nodeDelete(nextNode); //clear the nextNode because its not in a bag

                /*backtrace:
                backtracing checks the next item in the bag. if its not the current node  
                implying we have jumped back at least 1, we simply follow the backtrace 
                stack backwards and set the grid to 0 as we go*/
                if(!nodeSameLocation(currentNode,bag_peek(stack))){ 
                    while(!nodeSameLocation(bag_peek(stack),bag_peek(backtrace))){
                        btNode = bag_extract(backtrace);
                        grid[nodeGetRow(btNode)][nodeGetColumn(btNode)] = 0;
                        nodeDelete(btNode);
                    }
                }
            }
        }
        else{ //on full grid 
            if(gridCheck(grid)){  //check if it solves
                if(print){ //if print is enabled 
                    gridPrint(grid); //print the grid 
                    printf("\n");
                }
                solcount++; //add to count of solutions 
            }
            //same backtrace as above, here executed to jump back after checking a solution
            //this may be unnecessary because I do not think we will ever check an invalid solution
            if(!nodeSameLocation(currentNode,bag_peek(stack))){
                while(!nodeSameLocation(bag_peek(stack),bag_peek(backtrace))){
                    btNode = bag_extract(backtrace);
                    grid[nodeGetRow(btNode)][nodeGetColumn(btNode)] = 0;
                    nodeDelete(btNode);
                }
            }
        }

        //check for a backtrace and execute a backtrace if necessary
        nodeDelete(currentNode);
        currentNode = bag_extract(stack);
    }
    bag_delete(stack,nodeDelete); //clear bags
    bag_delete(backtrace,nodeDelete);
    printf("solcount: %d\n", solcount);
    return(solcount);
}

/* sudoku.c
*
* usage: runs the sudoku functions from a main driver
*
* input: if run with `create` as argument, sudoku builds a sudoku puzzle template in accordance with the specified requirements (i.e, with at least 40 zeros and a unique solution)  
* 	 if run with `solve` as argument, sudoku solves a sudoku puzzle grid passed as stdin  
*
* output: sudoku prints a grid to the screen; if run with `solve` as argument, also prints the number of solutions to the input puzzle to the screen
*
* stderr: error if incorrect number of input arguments received, or if the input argument is invalid
*
* C-Median: CS50 Spring 2020 final project
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#include "solve.h"
#include "shared.h"
#include "grid.h"
#include "create.h"
#include<time.h>


/********************** main *******************/
int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr,"Incorrect number of arguments\nUsage: ./sudoku command. \nSee readme for more\n");
        return 1;
    }
    if(strcmp(argv[1],"create")==0){
    	srand(time(NULL));
	int **grid = gridNew();
        create(grid);
        gridPrint(grid);
	gridDelete(grid);
    }
    else if(strcmp(argv[1],"solve")==0){
        int **grid = gridNew();
        gridCopy(grid);
        int numSol = solve(grid,true);	
        printf("number of solutions is: %d\n",numSol);
        gridDelete(grid);
    }
    else{
        fprintf(stderr,"Error, not a valid command\n");
        return 2;
    }

    return 0;
}

/* sudoku.c
*
* runs the sudoku functions from a main driver
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
	bool success = false;
	while (success != true) {
		create(grid);
		if (solve(grid, false) == 1) {
			success = true;
		}
		else {
			gridEmpty(grid);
		}
	}
	gridPrint(grid);
	gridDelete(grid);
    }
    else if(strcmp(argv[1],"solve")==0){
        int **grid = gridNew();
	gridCopy(grid);
        solve(grid,true);   
        gridDelete(grid);
    }
    else{
        fprintf(stderr,"Error, not a valid command\n");
        return 2;
    }

    return 0;
}

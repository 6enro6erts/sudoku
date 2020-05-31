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
//	int **grid1 = gridNew();
//	int **grid3 = gridNew();
//	bool success = false;
//	while (success != true) {
//		create(grid1);
//		int **grid2 = gridNew();
//		gridTransfer(grid2, grid1);
//		if (solve(grid1, false) == 1) {
//			gridTransfer(grid3, grid2);
//			success = true;
//			gridDelete(grid2);
//		}
//		else {
//			gridDelete(grid2);
//			gridEmpty(grid1);
//		}
//	}
//	gridPrint(grid3);
//	gridDelete(grid3);
//	gridDelete(grid1);
	int **grid = gridNew();
	gridEmpty(grid);
	gridPrint(grid);
	solve(grid, false);
	gridPrint(grid);
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

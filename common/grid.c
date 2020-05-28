/*
 * grid.c - implementation of the grid module
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int **gridNew(void);
void gridSet(int **grid, int row, int col, int value);
int gridGet(int **grid, int row, int col);
void gridDelete(int **grid);

/**************** gridNew *******************/
int **gridNew(void){
    int **grid = malloc(sizeof(int *)*9);
    
    if(grid == NULL){
        return NULL; //out of memory
    }
    else{
        for(int i = 0; i<9; i++){                       //create each new row
            grid[i] = malloc(sizeof(int)*9);
            for(int j = 0;j<9;j++){
                if(fscanf(stdin,"%d",&grid[i][j])==EOF){
                    fprintf(stderr,"Error with grid syntax");
                    return NULL;
                }
            }
        }
        return(grid);
    }
}

void gridSet(int **grid, int row, int col, int value){
	if (grid != NULL)
		grid[row][col] = value;
}

int gridGet(int **grid, int row, int col){
	return grid[row][col];
}

/***************** deleteGrid ************/
void gridDelete(int **grid){
    for(int i = 0;i<9;i++){
        free(grid[i]);
    }
    free(grid);
}

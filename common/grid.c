/*
 * grid.c - implementation of the grid module
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>
#include<math.h>

int **gridNew(void);
void gridSet(int **grid, int row, int col, int value);
int gridGet(int **grid, int row, int col);
bool gridCopy(int **grid); 
void gridTransfer(int **grid1, int **grid2);
void gridDelete(int **grid);



/**************** gridNew *******************/
/* allocates memory for a new grid */
int **gridNew(void){
    int **grid = malloc(sizeof(int *)*9);
    
    if(grid == NULL){
        return NULL; //out of memory
    }
    else{
        for(int i = 0; i<9; i++) {                       //create each new row
            grid[i] = malloc(sizeof(int)*9);
        }
        return(grid);
    }
}

/*************** gridCopy ***************/
/* Fills a grid with information to match grid from stdin */
bool gridCopy(int **grid) {
    for(int i = 0; i<9; i++) {                     
        for(int j = 0;j<9;j++){
            if(fscanf(stdin,"%d",&grid[i][j])==EOF){
                fprintf(stderr,"Error with grid syntax");
                return false;
            }
        }
    }
    return true; 
}   


/************* gridEmpty **************/  
/* fills grid with zeros */
void gridEmpty(int **grid) {
for (int i = 0; i < 9; i++ ) {
            for (int j = 0; j < 9; j++ ) {
                gridSet(grid, i, j, 0);
            }
        }
}

/************** gridTransfer ***************/
/* updates grid one to match grid2 */
void gridTransfer(int **grid1, int **grid2) {
	for(int i = 0; i<9; i++) {
        	for(int j = 0;j<9;j++){
            		gridSet(grid1, i, j, gridGet(grid2, i, j));
        	}
    	}
}

/***************** gridSet *********************/
/* sets the value of grid slot (i, j) to provided value */
void gridSet(int **grid, int row, int col, int value){
	if (grid != NULL)
		grid[row][col] = value;
}

/**************** gridGet ********************/
/* returns the value at grid slot (i, j) */
int gridGet(int **grid, int row, int col){
	if (grid != NULL)
		return grid[row][col];
	else
		return -1;
}

/**************** gridPrint ***************/  
/* prints the grid */
void gridPrint(int **grid){
    for(int i = 0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

/***************** gridDelete ************/
/* frees memory allocated by gridNew */
void gridDelete(int **grid){
    for(int i = 0;i<9;i++){
        free(grid[i]);
    }
    free(grid);
}



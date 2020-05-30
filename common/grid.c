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
void gridFill(int **grid);
void gridSet(int **grid, int row, int col, int value);
int gridGet(int **grid, int row, int col);
bool gridCopy(int **grid); 
void gridDelete(int **grid);
bool checkValue(int **grid, int i, int j, int value); 
void randFill(int **grid, int i, int j, int count); 

/**************** gridNew *******************/
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


void gridFill(int **grid) {
    int count = 0; 
    for (int i = 0; i < 9; i++ ) {
        for (int j = 0; j < 9; j++ ) {
            randFill(grid, i, j, count); 
        } 
    }
}

void randFill(int **grid, int i, int j, int count) {
    if ((rand() % 2) == 0 || count >= 40) {
        gridSet(grid, i, j, 0); 
    }
    else {
        int value = rand() % 10;
        if (value != 0) {
            bool success = false; 
            while (success != true) {
                if (checkValue(grid, i, j, value)) {
                    gridSet(grid, i, j, value); 
                    success = true; 
                    count++; 
                }
                else value = rand() %10;
            }
        }
    }
}

bool checkValue(int **grid, int i, int j, int value){
    //check row
    int row,column;
    row = i;
    for(column = 0; column < 9; column++){
        //printf("here. %d \n", column); 
        if( j !=column){
            if(grid[row][column] == value){
                //printf("returning false\n");
                return false;
            }
        }
    }

    //check column
    column = j;
    for(row = 0; row<9;row++){
        //printf("here now.\n");
        if(i !=row){
            if(grid[row][column] == value){
                return false;
            }
        }
    }

    //check square
    int topLeftRow, topLeftColumn;
    int rowCount = 0;
    int columnCount = 0;

    topLeftRow = (i/3)*3; //integer divide to get 0,1 or 2 then multiply by 3 to get the correct row index
    topLeftColumn = (j/3)*3; //same as row
    for(row = topLeftRow;rowCount<3;rowCount++){
        for(column = topLeftColumn;columnCount<3;columnCount++){
            if(i != row || j != column){
                if(grid[row][column]==value) {
                    return false;
                }
            }
            column++;
        }
        columnCount = 0;
        row++;
    }
    return true;
}

/***************** gridSet *********************/
void gridSet(int **grid, int row, int col, int value){
	if (grid != NULL)
		grid[row][col] = value;
}

/**************** gridGet ********************/
int gridGet(int **grid, int row, int col){
	if (grid != NULL)
		return grid[row][col];
	else
		return -1;
}

void gridPrint(int **grid){
    for(int i = 0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}
/***************** deleteGrid ************/
void gridDelete(int **grid){
    for(int i = 0;i<9;i++){
        free(grid[i]);
    }
    free(grid);
}

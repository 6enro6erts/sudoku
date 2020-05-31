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
void gridFill(int **grid);
void gridSet(int **grid, int row, int col, int value);
int gridGet(int **grid, int row, int col);
bool gridCopy(int **grid); 
void gridTransfer(int **grid1, int **grid2);
void gridDelete(int **grid);
bool checkValue(int **grid, int i, int j, int value); 
bool randFill(int **grid, int i, int j, int count); 
int fiftyFifty();
int randNine();


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

void gridEmpty(int **grid) {
for (int i = 0; i < 9; i++ ) {
            for (int j = 0; j < 9; j++ ) {
                gridSet(grid, i, j, 0);
            }
        }
}

void gridTransfer(int **grid1, int **grid2) {
	for(int i = 0; i<9; i++) {
        	for(int j = 0;j<9;j++){
            		gridSet(grid1, i, j, gridGet(grid2, i, j));
        	}
    	}
}
bool randFill(int **grid, int i, int j, int count) {
    if (fiftyFifty() == 0 || count >= 40) {
	gridSet(grid, i, j, 0);
	return true;
    }
    else {
	int v = 0;
	bool exit = false;
	while (v < 10 && !exit) {
        	int value = randNine();
        	if (value != 0) {    
                	if (checkValue(grid, i, j, value)) {
                    		gridSet(grid, i, j, value);  
                    		count++;
		    		return true;
                	}
                	else {
		        	v++;
		    	}
		}
	}
	return false;
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

/**************** fiftyFifty ***************/
int fiftyFifty() {
	int value = (rand() % 2);
	return value;
}

/**************** randNine ***************/
int randNine() {
	int value = (rand() % 9) + 1;
	return value;
}

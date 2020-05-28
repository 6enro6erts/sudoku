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


/********************* local function headers ***************/
void create(void);
int **newGrid(void);
void deleteGrid(int **grid);



/********************** main *******************/
int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr,"Incorrect number of arguments\nUsage: ./sudoku command. \nSee readme for more\n");
        return 1;
    }
    if(strcmp(argv[1],"create")==0){
        create();
    }
    else if(strcmp(argv[1],"solve")==0){
        int **grid = newGrid();
        solve(grid,true);
        deleteGrid(grid);
    }
    else{
        fprintf(stderr,"Error, not a valid command\n");
        return 2;
    }

    return 0;
}

/***************** create **********************/
void create(void){
    printf("called create\n");
}

/****************** newGrid ****************/
/*allocates a grid and reads it from stdin
returns NULL on errors in reading*/
int **newGrid(void){
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

/***************** deleteGrid ************/
/*frees the memory from a grid*/
void deleteGrid(int **grid){
    for(int i = 0;i<9;i++){
        free(grid[i]);
    }
    free(grid);
}


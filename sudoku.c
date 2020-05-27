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


/**************** local types ************************/
typedef struct node{
  int row;
  int column;
  int value;
} node_t;

/********************* local function headers ***************/
void create(void);
void solve(void);
int **newGrid(void);
void deleteGrid(int **grid);
node_t *newNode(int row, int column, int value);
void deleteNode(node_t* node);
bool checkNode(node_t *node, int **grid);


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
        solve();
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

/***************** solve *********************/

void solve(void){
    int **grid = newGrid();
    if(grid == NULL){
        printf("grid is null\n");
    }
    node_t *testnode = newNode(8,1,9);
    if(checkNode(testnode,grid)){
        printf("valid node!\n");
    }
    else printf("invalid node!\n");
    deleteNode(testnode);
    deleteGrid(grid);

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

/****************** newNode ****************/
/*initialize a new node to zero*/
node_t *newNode(int row, int column, int value){
    node_t *node = malloc(sizeof(node_t));
    if(node == NULL){
        return NULL;
    }
    else{
        node->row = row;
        node->column = column;
        node->value=value;
    }
    return(node);
}


/***************** deleteNode **************/
/*frees memory from a node */
void deleteNode(node_t* node){
    free(node);
}

/**************** checkNode ****************/
/*checks that a note is correctly placed:
return
True - there are no conflicts 
False - there is an error with the placement

Note: zeros are IGNORED, so a blank grid with one node will return true
*/
bool checkNode(node_t *node, int **grid){
    //check row
    int row,column;
    row = node->row;
    for(column = 0; column<9;column++){
        if(node->column!=column){
            if(grid[row][column]==node->value){
                return false;
            }
        }
    }

    //check column
    column = node->column;
    for(row = 0; row<9;row++){
        if(node->row!=row){
            if(grid[row][column]==node->value){
                return false;
            }
        }
    }

    //check square
    int topLeftRow, topLeftColumn;
    int rowCount = 0;
    int columnCount = 0;

    topLeftRow = ((node->row)/3)*3; //integer divide to get 0,1,2 then multiply by 3 to get the correct row
    topLeftColumn = ((node->column)/3)*3; //same as row
    for(row = topLeftRow;rowCount<3;rowCount++){
        for(column = topLeftColumn;columnCount<3;columnCount++){
            if(node->row != row || node->column != column){
                if(grid[row][column]==node->value){
                    return false;
                }
            }
        }
    }
    return true;
}
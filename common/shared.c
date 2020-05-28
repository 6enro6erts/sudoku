/* 
 * shared.c - fulfills shared.h
 *
 * 
 * shared stores functions used by solve and create, mostly validating aspects of the grid
 * C-median Dartmouth CS50 20S
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grid.h"
#include "node.h"
#include "bag.h"



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
    row = nodeGetRow(node);
    for(column = 0; column<9;column++){
        if(nodeGetColumn(node)!=column){
            if(grid[row][column]==nodeGetValue(node)){
                return false;
            }
        }
    }

    //check column
    column = nodeGetColumn(node);
    for(row = 0; row<9;row++){
        if(nodeGetRow(node)!=row){
            if(grid[row][column]==nodeGetValue(node)){
                return false;
            }
        }
    }

    //check square
    int topLeftRow, topLeftColumn;
    int rowCount = 0;
    int columnCount = 0;

    topLeftRow = ((nodeGetRow(node))/3)*3; //integer divide to get 0,1 or 2 then multiply by 3 to get the correct row index
    topLeftColumn = ((nodeGetColumn(node))/3)*3; //same as row
    for(row = topLeftRow;rowCount<3;rowCount++){
        for(column = topLeftColumn;columnCount<3;columnCount++){
            if(nodeGetRow(node) != row || nodeGetColumn(node) != column){
                if(grid[row][column]==nodeGetValue(node)){
                    return false;
                }
            }
        }
    }
    return true;
}

/********************* gimme **************/
/*checks to see if the given node has only one valid solution
return:
true: yes a gimme, value is set to correct value in grid and node
false: not a gimme*/
bool gimme(node_t *node,int **grid){
    int solution;
    int valueCount=0;

    for(int value=1;value<=9;value++){
        nodeSetValue(node,value);
        if(checkNode(node,grid)){
            solution = value;
            valueCount++;
        }
    }

    if(valueCount ==1){
        nodeSetValue(node,solution);
        grid[nodeGetRow(node)][nodeGetColumn(node)] = solution;
        return true;
    } else{
        nodeSetValue(node,0);
        return false;
    }
}
/******************* gimmeScanner **************/
/*scans a board and fills it with integers of gimmes until
there are no more*/
void gimmeScanner(int **grid){
    node_t *node;
    for(int gimmeCount = 1; gimmeCount>0;){
        gimmeCount = 0;
        for(int i = 0; i<9;i++){
            for(int j = 0;j<9;j++){
                if(grid[i][j]==0){
                    node = nodeNew(i,j,grid[i][j]);
                    if(gimme(node,grid)){
                        gimmeCount++;
                    }
                    nodeDelete(node);
                }
            }
        }
    }
}

/****************** pushGuesses **************/
/*takes a grid and bag, and pushes all valid guesses into the bag*/
void pushGuesses(node_t *node, int **grid, bag_t *bag){
    if(node != NULL){
        int row = nodeGetRow(node);
        int column = nodeGetColumn(node);
        node_t *testnode;
        for(int value = 1;value<=9;value++){
            testnode = nodeNew(row,column,value);
            if(checkNode(testnode,grid)){
                bag_insert(bag,testnode);
            }
            else nodeDelete(testnode);
        }
    }
}

/**************** getNextNode ***************/
/*gets the next zero in the grid and returns a node to that location*/
node_t *getNextNode(int **grid){
    for(int i=0; i<9;i++){
        for(int j=0;j<9;j++){
            if(grid[i][j]==0){
                return(nodeNew(i,j,0));
            }
        }
    }
    return NULL;
}

/**************** gridCheck ***************/
/*checks to see if a given board is a solution*/
bool gridCheck(int **grid){
    node_t *node;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            node = nodeNew(i,j,grid[i][j]);
            if(!checkNode(node,grid)){
                nodeDelete(node);
                return false;
            }
        }
    }
    nodeDelete(node);
    return true;
}
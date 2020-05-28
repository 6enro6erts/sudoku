/* 
 * node.c - fulfills from node.h


 * a node is a structure containg a row, column, and value
 * C-median Dartmouth CS50 20S
 */


#include <stdio.h>
#include <stdlib.h>

/**************** local types ************************/
typedef struct node{
  int row;
  int column;
  int value;
} node_t; 

/************** global functions *************/


/****************** nodeNew ****************/
/*initialize a new node to zero*/
node_t *nodeNew(int row, int column, int value){
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

/***************** nodeDelete **************/
/*frees memory from a node */
void nodeDelete(node_t* node){
    free(node);
}
/************** get methods ***************/
int nodeGetRow(node_t *node){ return node->row;}
int nodeGetColumn(node_t *node){ return node->column;}
int nodeGetValue(node_t *node){ return node->value;}
/************* set methods *******************/
void nodeSetRow(node_t *node, int row){node->row = row;}
void nodeSetColumn(node_t *node, int column){node->column = column;}
void nodeSetValue(node_t *node, int value){node->value = value;}

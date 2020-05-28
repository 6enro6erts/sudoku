/* 
 * node.c - fulfills from node.h


 * a node is a structure containg a row, column, and value
 * C-median Dartmouth CS50 20S
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**************** local types ************************/
typedef struct node{
  int row;
  int column;
  int value;
} node_t; 

/************** global functions *************/

/************** get methods ***************/
int nodeGetRow(node_t *node){ return node->row;}
int nodeGetColumn(node_t *node){ return node->column;}
int nodeGetValue(node_t *node){ return node->value;}
/************* set methods *******************/
void nodeSetRow(node_t *node, int row){node->row = row;}
void nodeSetColumn(node_t *node, int column){node->column = column;}
void nodeSetValue(node_t *node, int value){node->value = value;}

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
void nodeDelete(void* item){
    node_t *node = (node_t*)item;
    free(node);
}
/*************** nodeSameLocation ************/
/*check if two nodes are at the same location*/
bool nodeSameLocation(node_t *node1, node_t *node2){
    if(node1 == NULL || node2 == NULL){
        return true;
    }
    if(node1->row==node2->row){
        if(node1->column==node2->column){
            return true;
        }
    }
    return false;
}

/************************ nodePrint *****************/
/*print a comma seperated list of row,column,value for a node*/
void nodePrint(FILE *fp, void *item){
    node_t *node = (node_t*)item;
    printf("%d,%d,%d",node->row,node->column,node->value);
}

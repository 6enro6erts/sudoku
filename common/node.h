/* 
 * node.h - a header for node.c


 * a node is a structure containg a row, column, and value
 * C-median Dartmouth CS50 20S
 */


#include <stdio.h>
#include <stdlib.h>

/**************** global types ****************/
typedef struct node node_t;  // visible to to users outside of the module

/************** global functions *************/
/*creates a new node*/
node_t *nodeNew(int row, int column, int value);
/*delete a node*/
void nodeDelete(node_t* node);
/************* get methods *****************/
int nodeGetRow(node_t *node);
int nodeGetColumn(node_t *node);
int nodeGetValue(node_t *node);
/*************** set methods **************/
void nodeSetRow(node_t *node, int row);
void nodeSetColumn(node_t *node, int row);
void nodeSetValue(node_t *node, int row);

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
/*getters and setters for nodes*/
int nodeGetRow(node_t *node);
int nodeGetColumn(node_t *node);
int nodeGetValue(node_t *node);
void nodeSetRow(node_t *node);
void nodeSetColumn(node_t *node);
void nodeSetValue(node_t *node);

# Sudoku CS50: Implementation Spec C-median

## Overview

Sudoku has both create and solve modules. 

Create is implemented by filling in the grid randomly, while ensuring validity, until a grid with a unique solution is found. These grids are tested for uniqueness with solve. 

Solve is implemented by a simple DFS. It uses the `bag` structure as a stack, and adds guesses, stored as `node_t` strctures, to the bag. These nodes contain a position and value. The stack is retracted this stack when a possible solution runs into a deadend. Further explained in the psuedocode section.

The sudoku board is stored as a two-dimensional array of integers. 

## Pseudocode

### Create

### Solve

Solve is executed as a two-step process, first prefilling any gimmes, then running a DFS for the remaining options 

#### Gimmes

Gimmes are empty spaces in the grid with only a single possible answer. To find these, a gimmeScanner method is called. This method then calls a gimme method at each empty space on the grid, looping until there are no more gimmes. The gimme method checks every value (1-9) and returns true if only one of them is valid and false if more than one (or none) are valid. It additionally fills the slot in the grid with the correct value if it is a "gimme". 

### DFS 

The DFS makes use of a `bag` datatype, which is simply a LIFO linked list that is used as a stack. It also uses a `node_t` strucutre, which contains a row, column, and value for a slot in the grid. 

1. Two bags are created: a "stack" and a "backtrace" 

2. A getNextNode method is called to find the first empty node. It loops through the grid and returns a node at the next empty slot, or null.

3. A pushGuesses method is called to push all valid guesses for the first empty node to the stack. Valid guesses are checked by calling nodecheck which scans through the row,column,and surroudning box and makes sure that a guess value is not the same as another value.

4. The first node is popped from the stack and added to the backtrace 

5. The following loops until the bag is empty (ie there are no more valid guesses for anything )

    1. The grid adds the current guess to itself

    2. The next node is found with getNextNode

        1. If there is a next node: 
        
        2. All guesses are pushed to the stack

        3. The location of the node is pushed to the backtrace

        4. If there are no valid guesses, backtrace by popping an element from backtrace, setting the grid at that location to zero, then checking if the next element in the stack is at the same location of the next element in the backtrace. This will open up all nodes going backwards through the grid until we reach the next guess from the stack.

    3. If there is no next node(the grid is full) then a gridcheck method is called to ensure every spot on the grid is valid by looping through the grid and calling nodeCheck at each spot. If valid, the grid is printed and the solution count is iterated. 


## Function prototypes, parameters, and explanations

### solve

The main solve method is called by the sudoku function. 
```c
/*takes a grid and a value that says whether or not to print
* return number of solutions
*/
int solve(int **grid, bool print);
```
### create 

### common
Node, grid, bag, and shared libraries are used to create and manage these structures. This is where checking nodes and the grid can be found, alongside methods for pushing guesses to the bag. 

#### grid
```c
/************* global functions ******************/
/* Makes a 2D grid of integers, and returns this value. The user must free the grid or call gridDelete.*/
int **gridNew(void);

/* Sets the value of the grid at a certain point. Does nothing if the grid pointer is null.*/
void gridSet(int **grid, int row, int col, int value);

/* Gets the value of the grid at a certain point. Returns -1 if the grid pointer is null */
int gridGet(int **grid, int row, int col);

/* Frees each of the rows in the grid and the grid itself*/
void gridDelete(int **grid);

/* Prints the grid to stdout */
void gridPrint(int **grid);

/*copies a grid from stdin*/
bool gridCopy(int **grid);
/*checks a value in the grid to see if its valid in sudoku*/
bool checkValue(int **grid, int i, int j, int value); 
/*fills a grid until it has a unique solution. Used by create*/
void gridFill(int **grid);
/*fills a slot in the grid with a random, valid number*/
void randFill(int **grid, int i, int j, int count);
```

#### node 
```c
/**************** global types ****************/
typedef struct node node_t;  // invisible to to users outside of the module

/************** global functions *************/

/************* get methods *****************/
int nodeGetRow(node_t *node);
int nodeGetColumn(node_t *node);
int nodeGetValue(node_t *node);
/*************** set methods **************/
void nodeSetRow(node_t *node, int row);
void nodeSetColumn(node_t *node, int row);
void nodeSetValue(node_t *node, int row);

/*creates a new node*/
node_t *nodeNew(int row, int column, int value);
/*delete a node*/
void nodeDelete(void *item);
/*check if two nodes are at the same location*/
bool nodeSameLocation(node_t *node1, node_t *node2);
/*print a comma seperated list of row,column,value for a node*/
void nodePrint(FILE *fp, void *item);
```

#### bag 
```c
/**************** global types ****************/
typedef struct bag bag_t;  // opaque to users of the module

/**************** global functions ****************/
/* Create a new (empty) bag.*/
bag_t *bag_new(void);
/* Add new item to the bag.*/
void bag_insert(bag_t *bag, void *item);
/* Return the top data item from the bag, removing it from the bag */
void *bag_extract(bag_t *bag);
/*return the top item of the bag without removing it*/
void *bag_peek(bag_t *bag);
```
#### shared 
```c
/************** global functions ***********/
/*checks that a note is correctly placed:*/
bool checkNode(node_t *node, int **grid);

/*checks to see if the given node has only one valid solution */
int gimme(node_t *node,int **grid);

/*scans a board and fills it with integers of gimmes until
there are no more*/
void gimmeScanner(int **grid);

/*takes a grid and bag, and pushes all valid guesses into the bag */
bool pushGuesses(node_t *node, int **grid, bag_t *bag);

/*gets the next zero in the grid and returns a node to that location*/
node_t *getNextNode(int **grid);

/*checks to see if a given board is a solution*/
bool gridCheck(int **grid);
```

## Data structures

Grid: the grid was implemented as a 2D array of integers, technically an array of row arrays, where each row array contains 9 integers.

Bag: a LIFO linked list was used to ensure that the bag is a stack

Node: the node is a structure that contains three integers: a row, column, and value

## Error handling

### main errors

1 - wrong number of command line arguments

2- the command was not solve or create

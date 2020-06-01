# CS 50 final project: sudoku Design Spec

## User Interface

The sudoku interacts with a user through command line input, it has create or solve options

```bash

./sudoku create

./sudoku solve

```

## Inputs and Outputs

Input: solve takes an array of integers from stdin, generally piping in a file is most effective

Outputs: create outputs a plain text array of integers with numbers 1-9 and zeros as placeholders

solve ouputs an array of integers that represents the solved sudoku

## Functional decomposition into modules

1. *main* which parses the input array for errors then calls solver or create

2. *create* creates a unique sudoku that has ~40 numbers

3. *solve* take a sudoku 2D array of integers, and a boolean(true for print, false for please dont print) and returns the number of solutions (prints each on true, doesnt print on false)

4. *checkGrid* checks that the current array doesnt violate the rules of sudoku (error if any zeros)

5. *checkNode* given a number and position, check that there is not an immediate violation (ignore zeros)

6. *printGrid* prints a grid

7. *gimme* sees if there is ONLY one solution for a given item and returns it

## Pseudo code for logic/algorithmic flow

### create

1. call solve on an empty grid, producing a grid that is correctly filled in 

    1. pull number at random from grid

        1. check if grid has unique solution

            1. if not, pop out most recent and try again

            2. repeat until at least 40 numbers have been pulled from the grid  

### solve

STEP 1: -at the end if possible

scan through the grid, fill in any "gimmes" (only 1 possibility)

rank based on number of filled in surrounding squares (num of valid solutions) and add into nodeArray (do this at end maybe)

STEP 2:

1.validate guesses for first node

2.push the first node guesses into bag

3. repeat until we try every number:

    1. nextNode = getNode(currentNode):

    2. if an empty node is adjacent to currentNode

        1. add the empty node the backtrace
   
        2. for all guesses for the next node

        3. check a guess at the next node

            1. if at least one valid push that guess to the bag

            2. else backtrace to the next item in the stack

    3. if no adjacent empty node, check grid and store solution

## Dataflow through modules

main function check inputs and calls solve/create based on inputs

create uses a 2d array of ints to store the board 

solve uses a 2d array of ints to store the board, and a `node_t` structure to store guesses

checkGrid uses a 2d array of ints to check the grid 

checkNode uses the grid array and a node structure to check guesses

Major data structures

bag - stores the next node
grid - 2d array of ints
node - an x,y, and guess strucutre (all values are ints)

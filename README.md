# README for sudoku
C-Median, CS50, June 3, 2020

### Usage ###     
 
Create generates a board with at least 40 zeros and a unique solution. More or less can be added by adjusting the code. 
  
````
/* sudoku.c
*
* usage: runs the sudoku functions from a main driver
*
* input: if run with `create` as argument, sudoku builds a sudoku puzzle template in accordance with the specified requirements (i.e, with at least 40 zeros and a unique solution)  
*        if run with `solve` as argument, sudoku solves a sudoku puzzle grid passed as stdin  
*
* output: sudoku prints a grid to the screen; if run with `solve` as argument, also prints the number of solutions to the input puzzle to the screen
*
* stderr: error if incorrect number of input arguments received, or if the input argument is invalid
*
* C-Median: CS50 Spring 2020 final project
*/
````  
  
### Example Commandlines ###  
  
create a puzzle template:  
````  
./sudoku create   
````    
solve a puzzle template passed as stdin:  
```  
./sudoku solve < template  
````  
  
### Exit Status ###  
  
0 if success  
1 if issue with number of commandline arguments 
2 if unrecognized command line argument
  
  
### Assumptions ###  

-solve reads an input grid with fscanf. All whitespace will be ignored, only the first 81 numbers will be read, and any non integer characters will cause the immediate termination of the program.

### Presentation ###  

Our video presentation can be found here: https://youtu.be/2WwPsVfV0TM


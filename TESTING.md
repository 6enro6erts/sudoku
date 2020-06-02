# CS50 Project
## C-mdeian, CS50 Spring 2020

### Testing 'solve'
======

To test the solver, we wrote a fuzz testing module in solve/, performed unit testing, and wrote a script, testing.sh, that contains our testing.

### Unit Testing ###
(enter the solver directory)
make test  
./solveTest

The unit tests we performed are located in testing.sh

### Testing 'create' 

To test the creater, we performed unit testing, and wrote a testing.sh script.
=======
  
### Fuzztesting ###  
Fuzztesting is performed via the `testing.sh` bash script.
 
Commandline:
`./testing.sh -num_tests`, where `-num_tests` is an integer corresponding  
to the number of tests to be run. The results are printed to the screen.

OR

`make fuzztest`, where the number of tests run is determined by a Makefile   
variable. The results are piped into `testing.out`.  
  
Output:  
For each test, the output format includes:  
	- the template grid produced by `./sudoku create`    
	- the solution grid filled in by `./sudoku solve`  
	- the number of possible solutions to the template grid as determined  
	  by the solve function.  
  
Comments:  
`testing.sh` does not explicitly test the grids for their adherence to sudoku rules, as  
the solve function checks this internally via a call to `gridCheck()`.

### Unit testing ###
(enter the creator directory)
make test
./createTest

The unit tests we performed for testing are located in the testing.sh file  

Comments:  
when calling ./createTest multiple times, you must pause for 1 second in between each iteration in order to have a different grid template. Otherwise the creator will have the same seeding.

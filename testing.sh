#!/bin/bash
#
# File: testing.sh
#
# Description: fuzztesting for ./sudoku create, ./sudoku solve  
# 	      
#
# Input: User provides commandline argument denoting the number of tests to run
# Output: For each test, outputs create grid before and after solve
#
# C-Median, CS50, May 31, 2020


# Check to see if at least one argument given
if [ "$#" != 1 ]; then
    echo 1>&2 "Usage: one command line argument denoting number of tests to run"
    exit 1
fi


# For each argument, find it in array and print "field-number:field-name"
TEST_NUM=0
while [ $TEST_NUM -lt $1 ]; do  
	./sudoku create > file
	printf "Template:\n"
	cat file
	printf "\n"
	printf "Solution:\n"
        ./sudoku solve < file	
	printf  "–––––––––––––––––––––––––\n\n"
	((TEST_NUM = TEST_NUM + 1))
	sleep 1
done

exit 0

# Makefile for CS50 Final Project: Sudoku
#
# C-Median: Thomas Clark, Daniel McClafferty, Kuzi Mutsvangwa, Ben Roberts
# May, 27, 2020

# Variables
PROG = sudoku
OBJS = sudoku.o
L = ./common
LL = ./creator
LLL = ./solver
LIBS = $L/common.a
LIBS1 = $(LL)/create.a
LIBS2 = $(LLL)/solve.a
CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I $L -I $(LL) -I $(LLL)
CC = gcc
MAKE = make

# Rules
$(PROG): $(OBJS) $(LIBS1) $(LIBS2) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS): $(LL)/create.h $(LLL)/solve.h $L/shared.h $L/node.h $L/bag.h


# Phony targets
.PHONY: test clean

test:
	bash -v testing.sh &> testing.out

clean:
	rm -rf *.o
	rm -rf testing.out
	rm -rf *.dSYM

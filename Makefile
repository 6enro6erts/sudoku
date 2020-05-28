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
LIBS = $(L)/common.a
LIBS1 = $(LL)/create.a
LIBS2 = $(LLL)/solve.a
CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I $(L) -I $(LL) -I $(LLL)
CC = gcc
MAKE = make

$(PROG): $(OBJS) $(LIBS2) $(LIBS1) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@
$(OBJS): $(LLL)/solve.h $(LL)/create.h $(L)/shared.h $(L)/node.h $(L)/bag.h


# Phony targets
.PHONY: test clean libs cleanlibs
all: libs $(PROG)

libs:
	$(MAKE) -C common
	$(MAKE) -C solver
	$(MAKE) -C creator

test: $(PROG)
	./$(PROG) solve <testgrid

clean:
	rm -rf *.o
	rm -rf testing.out
	rm -rf *.dSYM
	rm -rf $(PROG)
	$(MAKE) -C common clean
	$(MAKE) -C creator clean
	$(MAKE) -C solver clean
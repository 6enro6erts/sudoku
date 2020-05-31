# Makefile for CS50 library
#   Builds and compiles all these utility functions into a library.
#
# David Kotz, April 2016, July 2017, April 2019
# Updated by Xia Zhou, July 2016
# Updated by Temi Prioleau, January 2020
# updated C-median Dartmouth CS50
# object files, and the target library
OBJS = bag.o hashtable.o grid.o node.o shared.o
LIB = common.a

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(FLAGS)
CC = gcc
MAKE = make

# Build the library by archiving object files
$(LIB): $(OBJS)
	ar cr $(LIB) $(OBJS)

# Dependencies: object files depend on header files
bag.o: bag.h
hashtable.o: hashtable.h
grid.o: grid.h 
node.o: node.h
shared.o: shared.h node.h grid.h

.PHONY: clean sourcelist

# list all the sources and docs in this directory.
# (this rule is used only by the Professor in preparing the starter kit)
sourcelist: Makefile *.md *.c *.h
	@echo $^

# clean up after our compilation
clean:
	rm -f core
	rm -f $(LIB) *~ *.o

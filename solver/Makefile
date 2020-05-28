# Makefile for 'common' module
#
# David Kotz, April 2016, 2017
# updated by Xia Zhou, July 2016
# updated by Temi Prioleau, January 2020

# PROG = 
OBJS = solver.o 
L = ../common
LIBS= $(L)/common.a


CFLAGS = -Wall -pedantic -std=c11 -ggdb -I$(L)
MAKE = make
CC = gcc

default: $(OBJS) $(LIBS)

solver.o: solver.h ../common/node.h ../common/grid.h  ../common/node.h 


.PHONY: clean

clean:
	rm -f *~ *.o *.dSYM

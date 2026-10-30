# Makefile for mini project 1 tic tac toe.
# copied from lab5 makefile
# modified by Luke Dykstra
#   make        build lab5part2 from lab5part2.c
#   make clean  delete what make built
#
# -g puts line numbers and variable names into the program,
# so gdb (or lldb on a Mac) can show you your own code.

CC     = gcc
CFLAGS = -Wall -Wextra -g

miniProject1: ticTacToe.c
	$(CC) $(CFLAGS) ticTacToe.c -o ticTacToe

clean:
	rm -rf ticTacToe ticTacToe.dSYM

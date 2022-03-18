## This is a simple Makefile 

# Define what compiler to use and the flags.
CC=cc
CXX=g++
CCFLAGS= -g -std=c++11 -Wall -Werror
LDLIBS= -lm
all: proj1

# Compile all .c files into .o files
# % matches all (like * in a command)
# $< is the source file (.c file)
%.o : %.cpp
	$(CXX) -c $(CCFLAGS) $<



###################################
# BEGIN SOLUTION
proj1: proj1.o 
	$(CXX) -o proj1 proj1.o  $(CCFLAGS) $(LDLIBS)


clean:
	rm -f *.o proj1
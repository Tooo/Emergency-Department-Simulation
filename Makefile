## This is a simple Makefile 

# Define what compiler to use and the flags.
CC=cc
CXX=g++
CCFLAGS= -g -std=c++11 -Wall -Werror
LDLIBS= -lm
SRC=$(wildcard *.cpp)

all: proj1



###################################
# BEGIN SOLUTION
proj1: $(SRC)
	$(CXX) -o proj1 $^ $(CCFLAGS) $(LDLIBS)


clean:
	rm -f *.o proj1
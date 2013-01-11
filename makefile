################################################################################
# Default makefile
################################################################################

#Global Variables
CC = g++
CFLAGS = -Wall

###############################
# Generate the linked list
###############################

#Variables for this portion
DIR = ./linkedlist/c++

#Create object files for everything.
Main: Node.o LinkedList.o $(DIR)/main.cpp
	$(CC) $(CFLAGS) -o Main $(DIR)/main.cpp Node.o LinkedList.o

Node.o: $(DIR)/Node.cpp $(DIR)/Node.h
	$(CC) $(CFlAGS) -c $(DIR)/Node.cpp

LinkedList.o: $(DIR)/LinkedList.cpp $(DIR)/LinkedList.h
	$(CC) $(CFLAGS) -c $(DIR)/LinkedList.cpp

clean:
	rm Main
	rm *.o

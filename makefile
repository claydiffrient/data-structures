################################################################################
# Default makefile
################################################################################

#Global Variables
CXXFLAGS = -Wall

###############################
# Generate the linked list
###############################

#Variables for this portion
DIR = ./linkedlist/c++

#Create object files for everything.
Main: Node.o LinkedList.o $(DIR)/main.cpp
	$(CXX) $(CXXFLAGS) -o Main $(DIR)/main.cpp Node.o LinkedList.o

Node.o: $(DIR)/Node.cpp $(DIR)/Node.h
	$(CXX) $(CXXFlAGS) -c $(DIR)/Node.cpp

LinkedList.o: $(DIR)/LinkedList.cpp $(DIR)/LinkedList.h
	$(CXX) $(CXXFLAGS) -c $(DIR)/LinkedList.cpp

clean:
	rm Main
	rm *.o

################################################################################
# Default makefile
################################################################################

#Compiler flags
CXXFLAGS = -Wall
#LinkedList Directory
LLDIR = ./linked-list
#DoublyLinkedList Directory
DLLDIR = ./doubly-linked-list



###############################
# No argument - make all
###############################

all: linkedlist doublylinkedlist

###############################
# Generate the linked list
###############################

linkedlist: Node.o LinkedList.o $(LLDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -o LinkedList $(LLDIR)/main.cpp Node.o LinkedList.o

Node.o: $(LLDIR)/Node.cpp $(LLDIR)/Node.h
	$(CXX) $(CXXFlAGS) -c $(LLDIR)/Node.cpp

LinkedList.o: $(LLDIR)/LinkedList.cpp $(LLDIR)/LinkedList.h
	$(CXX) $(CXXFLAGS) -c $(LLDIR)/LinkedList.cpp

###############################
# Generate the Doubly Linked List
###############################

doublylinkedlist: dNode.o dLinkedList.o $(DLLDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -o DLinkedList $(DLLDIR)/main.cpp dNode.o dLinkedList.o

dNode.o: $(DLLDIR)/Node.cpp $(DLLDIR)/Node.h
	$(CXX) $(CXXFlAGS) -o dNode.o -c $(LLDIR)/Node.cpp

dLinkedList.o: $(DLLDIR)/LinkedList.cpp $(DLLDIR)/LinkedList.h
	$(CXX) $(CXXFLAGS) -o dLinkedList.o -c $(LLDIR)/LinkedList.cpp


clean:
	rm DLinkedList
	rm LinkedList
	rm *.o

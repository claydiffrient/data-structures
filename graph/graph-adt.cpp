/*******************************************************************************
* CS 235 Assignment 19
* Written by Clay Diffrient
*******************************************************************************/

#include<iostream>
#include<cstdlib>
#include<vector>
#include<stdexcept>
using namespace std;


class Node
{
   public:
      Node(int pValue);
      ~Node();
      void setNext(Node* pNext) { mNext = pNext;}
      Node* getNext() { return mNext;}
      int getValue() { return mValue;}
      void setValue(int pValue) { mValue = pValue;}
   private:
      int mValue;
      Node* mNext;
};

class Graph
{
   public:
      Graph();
      ~Graph();
      bool isEmpty();
      bool insertNewNode(int pValue);
      bool insertDirectedEdge(int pFirstNodeValue, int pSecondNodeValue);
      void displayGraph();
   private:
      vector<Node*>* mAdjacencyList;
};

/*******************************************************************************
* Graph Constructor
* Creates a new empty graph.
*******************************************************************************/
Graph::Graph()
{
   mAdjacencyList = new vector<Node*>();
}

/*******************************************************************************
* Graph Destructor
*******************************************************************************/
Graph::~Graph()
{
   for (int i = 0; i < mAdjacencyList->size(); i++)
   {
      Node* current = mAdjacencyList->at(i);
      while (current != NULL)
      {
         Node* next = current->getNext();
         delete current;
         current = next;
      }
   }
   delete mAdjacencyList;
}

/*******************************************************************************
* isEmpty
* Determines if the graph is empty.
*******************************************************************************/
bool Graph::isEmpty()
{
   return mAdjacencyList->empty();
}

/*******************************************************************************
* insertNewNode
* Creates a new node in the graph.
*******************************************************************************/
bool Graph::insertNewNode(int pValue)
{
   mAdjacencyList->push_back(new Node(pValue));
}

/*******************************************************************************
* insertDirectedEdge
* Creates an edge from the FirstNode to the SecondNode.
* If an edge to that particular node already exists it, will not create another.
*******************************************************************************/
bool Graph::insertDirectedEdge(int pFirstNodeValue, int pSecondNodeValue)
{
   if ((pFirstNodeValue == 0) || (pSecondNodeValue == 0))
   {
      cerr << "A node value cannot be zero (0).\n";
      return false;
   }

   Node* startNode;
   Node* endNode;
   try
   {
      startNode = mAdjacencyList->at(pFirstNodeValue - 1);
   }
   catch (const out_of_range& outOfRange)
   {
      cerr << "The first node doesn't exist.\n";
      return false;
   }
   try
   {
      endNode = mAdjacencyList->at(pSecondNodeValue - 1);
   }
   catch (const out_of_range& outOfRange)
   {
      cerr << "The second node doesn't exist.\n";
      return false;
   }

   while (startNode->getNext() != NULL)
   {
      startNode = startNode->getNext();
      if (startNode->getValue() == pSecondNodeValue)
      {
         cerr << "The directed edge already exists.\n";
         return false;
      }
   }

   startNode->setNext(new Node(pSecondNodeValue));
   return true;
}

/*******************************************************************************
* displayGraph
* Displays the graph as an adjacency list representation.
*******************************************************************************/
void Graph::displayGraph()
{
   if (isEmpty())
   {
      cerr << "The graph is empty.\n";
   }
   else
   {
      for (int i = 0; i < mAdjacencyList->size(); i++)
      {
         cout << "Node " << i + 1 << " -> ";
         Node* myNode;
         myNode = mAdjacencyList->at(i)->getNext();
         while (myNode != NULL)
         {
            cout << myNode->getValue();
            myNode = myNode->getNext();
            if (myNode != NULL)
            {
               cout << ", ";
            }
         }
         cout << endl;
      }
   }
}

/*******************************************************************************
* Node Constructor
* Creates a new node with the given value.
*******************************************************************************/
Node::Node(int pValue)
{
   mValue = pValue;
   mNext = NULL;
}

/*******************************************************************************
* Node Destructor
*******************************************************************************/
Node::~Node()
{
   //Intentionally left blank.
}

/*******************************************************************************
* Main
* Tests the classes contained
*******************************************************************************/
int main()
{
   Graph myGraph;
   myGraph.insertNewNode(1);
   myGraph.insertNewNode(2);
   myGraph.insertNewNode(3);
   myGraph.insertNewNode(4);
   myGraph.insertNewNode(5);
   myGraph.insertNewNode(6);
   myGraph.insertDirectedEdge(1, 2);
   myGraph.insertDirectedEdge(1, 4);
   myGraph.insertDirectedEdge(1, 5);
   myGraph.insertDirectedEdge(2, 3);
   myGraph.insertDirectedEdge(2, 4);
   myGraph.insertDirectedEdge(3, 3);
   myGraph.insertDirectedEdge(4, 2);
   myGraph.insertDirectedEdge(4, 3);
   myGraph.insertDirectedEdge(6, 2);
   myGraph.insertDirectedEdge(6, 3);
   myGraph.displayGraph();
   return 0;
}
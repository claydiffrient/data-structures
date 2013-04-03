/*******************************************************************************
* CS 235 Assignment 20
* Written by Clay Diffrient
*******************************************************************************/

#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<vector>
using namespace std;

/*******************************************************************************
* Edge
* Implementation of an edge.
*******************************************************************************/
class Edge
{
   public:
      Edge(int pDestination, int pWeight);
      Edge(int pValue);
      int getWeight() {return mWeight;}
      int getDestination() {return mDestination;}
      Edge* getNext() { return mNext;}
      void setNext(Edge* pNext) {mNext = pNext;}
      int getValue() {return mValue;}
      void setValue(int pValue) {mValue = pValue;}
   private:
      int mValue;
      int mDestination;
      int mWeight;
      Edge* mNext;
};



/*******************************************************************************
* Graph
* Provides an simple implementation of a directed graph.
*******************************************************************************/
class Graph
{
   public:
      Graph();
      Graph(ifstream& pGraphData);
      ~Graph();
      bool isEmpty();
      Edge* insertNode(int pValue);
      bool insertEdge(int pFirstNodeValue, int pSecondNodeValue, int pWeight);
      string findShortestPath(int pStartNode, int pEndNode);
      void displayGraph();
   private:
      vector<Edge*>* mAdjacencyList;
};

/*******************************************************************************
* Starter Edge Constructor
*******************************************************************************/
Edge::Edge(int pValue)
{
   mDestination = -1;
   mWeight = -1;
   mValue = pValue;
}

/*******************************************************************************
* Edge Constructor
*******************************************************************************/
Edge::Edge(int pDestination, int pWeight)
{
   mDestination = pDestination;
   mWeight = pWeight;
   mValue = -1;
}

/*******************************************************************************
* Graph Constructor
* Creates a new empty graph.
*******************************************************************************/
Graph::Graph()
{
   mAdjacencyList = new vector<Edge*>();
}

/*******************************************************************************
* Graph Contructor
* Creates a graph based on an input stream.
*******************************************************************************/
Graph::Graph(ifstream& pGraphData)
{
   mAdjacencyList = new vector<Edge*>();
   string curString;
   int startNode;
   int destinationNode;
   int weight;
   while (getline(pGraphData, curString))
   {
      istringstream curStringStream(curString);
      curStringStream >> startNode;
      while (curStringStream >> destinationNode >> weight)
      {
         cout << "Start: " << startNode << " End: " << destinationNode
              << " Weight: " << weight << endl;
         insertEdge(startNode, destinationNode, weight);
      }
   }
}

/*******************************************************************************
* Graph Destructor
*******************************************************************************/
Graph::~Graph()
{
/*   for (int i = 0; i < mAdjacencyList->size(); i++)
   {
      Edge* current = mAdjacencyList->at(i);
      while (current != NULL)
      {
         Edge* next = current->getNext();
         delete current;
         current = next;
      }
   }
   delete mAdjacencyList;*/
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
* insertNode
* Creates a new node in the graph.
* Returns a pointer to the node if it exists, if it doesn't it creates a node
* and returns a pointer to it.
*******************************************************************************/
Edge* Graph::insertNode(int pValue)
{
   vector<Edge*>::iterator it;
   for (it = mAdjacencyList->begin(); it != mAdjacencyList->end(); it++)
   {
      //cout << "Trying to find " << pValue << ", checking " << (*it)->getValue() << endl;
      if ((*it)->getValue() == pValue)
      {
         cout << "Found " << pValue << endl;
         return *it;
      }
   }
   Edge* newEdge;
   newEdge = new Edge(pValue);
   cout << "Not found. Inserting new node " << pValue << endl;
   mAdjacencyList->push_back(newEdge);
   return newEdge;
}

/*******************************************************************************
* insertEdge
* Creates an edge from the FirstNode to the SecondNode.
* If an edge to that particular node already exists it, will not create another.
*******************************************************************************/
bool Graph::insertEdge(int pFirstNodeValue, int pSecondNodeValue,
                               int pWeight)
{
   if ((pFirstNodeValue < 0) || (pSecondNodeValue < 0))
   {
      cerr << "A node value cannot be less than zero (0).\n";
      return false;
   }

   Edge* startNode;
   Edge* endNode;

   startNode = insertNode(pFirstNodeValue);
   endNode = insertNode(pSecondNodeValue);

   while (startNode->getNext() != NULL)
   {
      startNode = startNode->getNext();
      if (startNode->getDestination() == pSecondNodeValue)
      {
         cerr << "The edge from " << pFirstNodeValue
              << " to " << pSecondNodeValue << " already exists.\n";
         return false;
      }
   }
   cerr << "Inserting edge from " << pFirstNodeValue
              << " to " << pSecondNodeValue << " with weight " << pWeight << "\n\n";
   startNode->setNext(new Edge(pSecondNodeValue, pWeight));

/*   while (endNode->getNext() != NULL)
   {
      endNode = endNode->getNext();
   }*/

   //endNode->setNext(new Edge(pFirstNodeValue, pWeight));
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
      vector<Edge*>::iterator it;
      for (it = mAdjacencyList->begin(); it != mAdjacencyList->end(); it++)
      {
         cout << "Node " << (*it)->getValue() << " -> ";
         Edge* myNode;
         myNode = (*it)->getNext();
         while (myNode != NULL)
         {
            cout << "[" << myNode->getDestination() << ", "
                 << myNode->getWeight() << "]";
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
* findShortestPath
* Runs through the shortest path algorithm and outputs a string with the path.
*******************************************************************************/
string Graph::findShortestPath(int pStartNode, int pEndNode)
{
   stringstream returnData;
   returnData << pStartNode << " to " << pEndNode;
   return returnData.str();
}

/*******************************************************************************
* getInteger
* Returns an integer.  Returns the given error message upon errors.
*******************************************************************************/
int getInteger(string pPrompt, string pErrorMessage)
{
   int inputData;
   cout << pPrompt;
   cin >> inputData;
   while (cin.fail())
   {
      cin.clear();
      cin.ignore(80, '\n');
      cout << pErrorMessage << endl << pPrompt;
      cin >> inputData;
   }
   return inputData;
}


/*******************************************************************************
* Main
* Tests the classes contained
*******************************************************************************/
int main(int argc, char** argv)
{
   if (argc != 2)
   {
      cerr << "Invalid Input.\n Usage: shortest-path filenameOfGraph\n";
      exit(1);
   }
   else
   {
      ifstream inputData;
      int startNode;
      int endNode;
      inputData.open(argv[1]);
      if (inputData.fail())
      {
         cout << "The provided file doesn't exist. Try again" << endl;
         exit(1);
      }
      Graph myGraph(inputData);

      myGraph.displayGraph();
      /*startNode = getInteger("Start Node:", "Invalid input, try again.");
      endNode = getInteger("End Node:", "Invalid input, try again.");
      cout << myGraph.findShortestPath(startNode, endNode) << endl;*/
   }
   return 0;
}
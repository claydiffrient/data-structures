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
      int getWeight() {return mWeight;}
      int getDestination() {return mDestination;}
   private:
      int mDestination;
      int mWeight;
};

/*******************************************************************************
* Node
* Implmentation of a Node.
*******************************************************************************/
class Node
{
   public:
      Node(int pValue);
      int getValue() {return mValue;}
      vector<Edge*>* getEdges() {return mConnections;}
   private:
      vector<Edge*>* mConnections;
      int mValue;
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
      Node* insertNode(int pValue);
      bool insertEdge(int pFirstNodeValue, int pSecondNodeValue, int pWeight);
      string findShortestPath(int pStartNode, int pEndNode);
      void displayGraph();
   private:
      vector<Node*>* mNodes;
};

/*******************************************************************************
* Node Constructor
*******************************************************************************/
Node::Node(int pValue)
{
   mValue = pValue;
   mConnections = new vector<Edge*>();
}

/*******************************************************************************
* Edge Constructor
*******************************************************************************/
Edge::Edge(int pDestination, int pWeight)
{
   mDestination = pDestination;
   mWeight = pWeight;
}

/*******************************************************************************
* Graph Constructor
* Creates a new empty graph.
*******************************************************************************/
Graph::Graph()
{
   mNodes = new vector<Node*>();
}

/*******************************************************************************
* Graph Contructor
* Creates a graph based on an input stream.
*******************************************************************************/
Graph::Graph(ifstream& pGraphData)
{
   mNodes = new vector<Node*>();
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
   return mNodes->empty();
}

/*******************************************************************************
* insertNode
* Creates a new node in the graph.
* Returns a pointer to the node if it exists, if it doesn't it creates a node
* and returns a pointer to it.
*******************************************************************************/
Node* Graph::insertNode(int pValue)
{
   vector<Node*>::iterator it;
   for (it = mNodes->begin(); it != mNodes->end(); it++)
   {
      if ((*it)->getValue() == pValue)
      {
         return *it;
      }
   }
   Node* newNode;
   newNode = new Node(pValue);
   mNodes->push_back(newNode);
   return newNode;
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

   Node* startNode;
   Node* endNode;

   startNode = insertNode(pFirstNodeValue);
   endNode = insertNode(pSecondNodeValue);

   vector<Edge*>::iterator startNodeIter;
   vector<Edge*>* startEdges;
   startEdges = startNode->getEdges();

   for (startNodeIter = startEdges->begin(); startNodeIter != startEdges->end(); startNodeIter++)
   {
      if ((*startNodeIter)->getDestination() == pSecondNodeValue)
      {
         cerr << "The edge from " << pFirstNodeValue
              << " to " << pSecondNodeValue << " already exists.\n";
         return false;
      }
   }
   startEdges->push_back(new Edge(pSecondNodeValue, pWeight));
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
      vector<Node*>::iterator nodeIt;
      vector<Edge*>::iterator edgeIt;
      for (nodeIt = mNodes->begin(); nodeIt != mNodes->end(); nodeIt++)
      {
         cout << "Node " << (*nodeIt)->getValue() << " -> ";
         vector<Edge*>* edges;
         edges = (*nodeIt)->getEdges();
         for (edgeIt = edges->begin(); edgeIt != edges->end(); edgeIt++)
         {
            cout << "[" << (*edgeIt)->getDestination() << ", "
                 << (*edgeIt)->getWeight() << "] ";
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
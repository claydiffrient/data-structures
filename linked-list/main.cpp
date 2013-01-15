/*******************************************************************************
* Main for testing purposes.
*******************************************************************************/

#include "LinkedList.cpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
   Node<int>* myNode;
   myNode = new Node<int>();

   LinkedList<int>* myList;
   myList = new LinkedList<int>();
   myList->insertAtEnd(myNode);

   return 0;
}
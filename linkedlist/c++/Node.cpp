/*******************************************************************************
* Implementation file containing Node class definitions.
*******************************************************************************/

#include "Node.h"
#include <cstddef>
using namespace std;

/*************************************************************************
* Default constructor.
*************************************************************************/
template<class T>
Node<T>::Node()
{
   mValue = 0;
   mNext = NULL;
}

/*************************************************************************
* Default destructor
*************************************************************************/
template<class T>
Node<T>::~Node()
{
   //TODO: Implement this.
}

/*************************************************************************
* getValue
* Returns the value
*************************************************************************/
template<class T>
T Node<T>::getValue()
{
   return mValue;
}

/*************************************************************************
* setValue
* Sets the node's value to the given value
*************************************************************************/
template<class T>
void Node<T>::setValue(T value)
{
   mValue = value;
}

/*******************************************************************************
* getNext
* Returns a pointer to the next node.
*******************************************************************************/
template<class T>
Node<T>* Node<T>::getNext()
{
   return mNext;
}

/*******************************************************************************
* setNext
* Sets the next node pointer to the given node.
*******************************************************************************/
template<class T>
void Node<T>::setNext(Node* next)
{
   return next;
}
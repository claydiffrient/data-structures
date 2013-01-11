/*******************************************************************************
* Implementation file containing the LinkedList Class Definitions
*******************************************************************************/

#include "LinkedList.h"
using namespace std;

/*************************************************************************
* Default constructor
*************************************************************************/
template<class T>
LinkedList<T>::LinkedList()
{
   mHead = NULL;
   mSize = 0;
}

/*************************************************************************
* Default destructor
*************************************************************************/
template<class T>
LinkedList<T>::~LinkedList()
{
   //TODO: Implement this.
}

/*************************************************************************
* setHead
* Sets the head value to the given value.
*************************************************************************/
template<class T>
void LinkedList<T>::setHead(Node<T>* head)
{
   mHead = head;
}

/*************************************************************************
* getHead
* Returns the head node.
*************************************************************************/
template<class T>
Node<T>* LinkedList<T>::getHead()
{
   return mHead;
}
/*************************************************************************
* setSize
* Sets the size to the given value.
*************************************************************************/
template<class T>
void LinkedList<T>::setSize(int size)
{
   mSize = size;
}
/*************************************************************************
* getSize
* Returns the size of the linked list.
*************************************************************************/
template<class T>
int LinkedList<T>::getSize()
{
   return mSize;
}
/*************************************************************************
* insertAtEnd
* Inserts the given node reference at the end of the list.
*************************************************************************/
void insertAtEnd(Node<T>* node)
{
   Node<T>* last = traverse();
   last.setNext(node);
}
/*************************************************************************
* insertAtBeginning
* Inserts the given node reference at the beginning of the list.
*************************************************************************/
void insertAtBeginning(Node<T>* node);
/*************************************************************************
* removeFirst
* Removes the first element from the list.
*************************************************************************/
void removeFirst();
/*************************************************************************
* removeLast
* Removes the last element from the list.
*************************************************************************/
void removeLast();
/*************************************************************************
* traverse
* Returns a pointer to the last node of the list.
*************************************************************************/
template<class T>
Node<T>* LinkedList<T>::traverse()
{
   Node<T>* first = mHead;
   if (first != NULL)
   {
      while (first->getNext() != NULL)
      {
         first = first->getNext();
      }
   }
   return first;
}

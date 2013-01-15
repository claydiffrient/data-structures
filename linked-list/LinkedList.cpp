/*******************************************************************************
* Implementation file containing the LinkedList Class Definitions
*******************************************************************************/

#include "LinkedList.h"
#include <iostream>
using namespace std;

/*************************************************************************
* Default constructor
*************************************************************************/
template<class T>
LinkedList<T>::LinkedList()
{
   mHead = new Node<T>();
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
template<class T>
void LinkedList<T>::insertAtEnd(Node<T>* node)
{
   if (mSize == 0)
   {

      mHead->setNext(node);
   }
   else
   {
      Node<T>* last = traverse();
      if (last != NULL)
      {
         last->setNext(node);
         mSize++;
      }
      else
      {
         cerr << "An error occurred when inserting at the end." << endl;
      }
   }
}

/*************************************************************************
* insertAtBeginning
* Inserts the given node reference at the beginning of the list.
*************************************************************************/
template<class T>
void LinkedList<T>::insertAtBeginning(Node<T>* node)
{
   Node<T>* temp = mHead->getNext();
   if (temp != NULL)
   {
      node->setNext(temp);
      mHead->setNext(node);
      mSize++;
   }
   else
   {
      mHead->setNext(node);
   }
}

/*************************************************************************
* removeFirst
* Removes the first element from the list.
*************************************************************************/
template<class T>
void LinkedList<T>::removeFirst()
{
   Node<T>* first = mHead->getNext();
   if (first != NULL)
   {
      Node<T>* newFirst = first->getNext();
      mHead->setNext(newFirst);
      delete first;
      mSize--;
   }
   else
   {
      cerr << "There are no nodes in the list.";
   }
}
/*************************************************************************
* removeLast
* Removes the last element from the list.
*************************************************************************/
template<class T>
void LinkedList<T>::removeLast()
{
   Node<T>* last = traverse();
   delete last;
   mSize--;
}
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

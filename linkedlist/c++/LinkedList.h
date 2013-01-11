/*******************************************************************************
* Header file for the LinkedList Class Declaration
*******************************************************************************/

##ifndef LINKED_LIST_T
#define LINKED_LIST_T

#include "Node.cpp"
using namespace std;

template<class T>
class LinkedList
{
   private:
      Node<T>* mHead;   //Pointer the first element.
      int mSize;        //Number of elements present.
   public:
      /*************************************************************************
      * Default constructor
      *************************************************************************/
      LinkedList();
      /*************************************************************************
      * Default destructor
      *************************************************************************/
      ~LinkedList();
      /*************************************************************************
      * setHead
      * Sets the head value to the given value.
      *************************************************************************/
      void setHead(Node<T>* head);
      /*************************************************************************
      * getHead
      * Returns the head node.
      *************************************************************************/
      Node<T>* getHead();
      /*************************************************************************
      * setSize
      * Sets the size to the given value.
      *************************************************************************/
      void setSize(int size);
      /*************************************************************************
      * getSize
      * Returns the size of the linked list.
      *************************************************************************/
      int getSize();
      /*************************************************************************
      * insertAtEnd
      * Inserts the given node reference at the end of the list.
      *************************************************************************/
      void insertAtEnd(Node<T>* node);
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
      * Follows the nodes and returns a pointer to the last node.
      *************************************************************************/
      Node<T>* traverse();
};

#endif
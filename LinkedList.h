/*******************************************************************************
* Header file for the LinkedList Class Declaration
*******************************************************************************/
#include "Node.h"
using namespace std;

template<class T>
class LinkedList
{
   private:
      Node<T>* mHead;
      int mSize;
   public:
      LinkedList();
      ~LinkedList();
};
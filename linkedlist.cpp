#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
class Node
{
   private:
      T mValue;
      Node<T>* mNext;
   public:
      /*************************************************************************
      * Default constructor.
      *************************************************************************/
      Node()
      {
         mValue = 0;
         mNext = NULL;
      }
      ~Node()
      {

      }

      T getValue() {return mValue;}
      void setValue(T value) {mValue = value;}
      Node<T>* getNext() {return mNext;}
      void setNext(Node* next) {mNext = next;}
};

int main(int argc, char const *argv[])
{
   Node<int> myNode;
   cout << myNode.getValue() << endl;
   myNode.setNext(new Node<int>());
   for (int i = 0; i < 10; i++)
   {
      myNode.getNext()->setNext(new Node<int>());
      if (i == 9)
      {
         myNode.getNext()->setNext(NULL);
      }
   }
   while (myNode.getNext() != NULL)
   {
      cout << myNode.getNext()->getValue() << " ";
      myNode.setNext(myNode.getNext());
   }

   return 0;
}
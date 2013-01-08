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
         mNext = new Node<T>();
      }
      ~Node()
      {

      }

      T getValue() {return mValue;}
      void setValue(T value) {mValue = value;}
      Node<T> getNext() {return mNext;}
      void setNext(Node* next) {mNext = next;}
};

int main(int argc, char const *argv[])
{
   Node<int> aNode;
   aNode.setValue(1);
   aNode.setNext(new Node<int>());

   return 0;
}
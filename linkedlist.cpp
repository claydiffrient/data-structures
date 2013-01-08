#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
   private:
      int mValue;
      Node* mNext;
   public:
      /*************************************************************************
      * Default constructor.
      *************************************************************************/
      Node()
      {
         mValue = 0;
         mNext = new Node();
      }
      ~Node()
      {

      }

      int getValue() {return mValue;}
      void setValue(int value) {mValue = value;}
      Node getNext() {return mNext;}
      void setNext(Node* next) {mNext = next;}
};

int main(int argc, char const *argv[])
{
   Node aNode();
   aNode->setValue(1);
   aNode->setNext(new Node());

   return 0;
}
# 1 "Node.h"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "Node.h"




using namespace std;

template<class T>
class Node
{
   private:
      T mValue;
      Node<T>* mNext;
   public:
      


      Node();
      ~Node();

      T getValue();
      void setValue(T value);
      Node<T>* getNext();
      void setNext(Node* next);
};

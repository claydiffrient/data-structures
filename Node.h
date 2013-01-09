/*******************************************************************************
* Header file containing Node class declarations.
*******************************************************************************/

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
      Node();
      ~Node();

      T getValue();
      void setValue(T value);
      Node<T>* getNext();
      void setNext(Node* next);
};
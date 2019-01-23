#include <iostream>
#include <fstream>
#include <string>

#include "elem.h"
typedef el_t Elem;
using namespace std;

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //check if llist is empty
  bool isEmpty();
    
  //displays all elements of ll
  void displayAll();

  //adds to front of linked list
  void addFront(el_t);
    
  //adds to rear of ll
  void addRear(el_t);

  //deletes front of ll
  void deleteFront(el_t&);
    
  //deletes rear of ll
  void deleteRear(el_t&);
    
  //deletes in a specific given point of the ll
  void deleteIth(int, el_t&);

  //inserts in specific point of ll
  void insertIth(int, el_t);

  //Copy Constructor to allow pass by value and return by value
  llist(const llist&);
  
  //Overloading of = 
  llist& operator=(const llist&); 
};

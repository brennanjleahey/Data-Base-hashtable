#include "slist.h"
#include <iostream>

using namespace std;

slist::slist()
{

}

int slist::search (el_t key)
 {
  // search through the list to see if any node contains the key.
  // If so, return its position (>=1). Otherwise, return 0.
   Node *p = Front;     //point to front of the list
  int elemNum = 1;      
  while (p != NULL)
    {
      if (p->Elem == key)  //if element is found return it
	{return elemNum;}
      p = p->Next;         //if not, move to next element
      elemNum++;
    }
  return 0;
}
Elem slist::search2 (el_t key)
{
  int index = 0;
  Node *temp = Front;
  el_t funct;

  if(!isEmpty())
    {
      while(!(temp==NULL))
        {
          index++; //increment slot
          if(temp->Elem == key)
            {
              return temp->Elem; //element
            }

          temp=temp->Next;
        }
    }
  if(isEmpty())
    return funct;

  return funct;
}
void slist::replace(el_t rep, int a)
{
  // go to the Ith node (if I is between 1 and Count) and
  // replace the element there with the new element.
  // If I was an illegal value, throw OutOfRange
  if (a < 1 || a > Count)         //check if index is out of range
    {throw OutOfRange();}
  Node *p = Front;                //point to front of the list and get to desired element
  for (int i = 1; i < a; i++)
    {p = p->Next;}
  p->Elem = rep;                  //replace
}

bool slist::operator==(const slist& a)
{ 
  if (this->Count == a.Count) 
    {                                 //compare the count between two slists
      Node *p1 = a.Front;             //set p1 to passed/rhs slist 
      Node *p2 = this->Front;          //set p2 to lhs slist
    while (p1 != NULL && p2 != NULL) {    //while not at end of list
      if (!(p2->Elem == p1->Elem))           //If an elem doesn't match, it's not the same
      {return false;}
      p2 = p2->Next;                   //else continue through rest of lists
      p1 = p1->Next;
    }
    return true;                       //if all elements match
  }
  return false;                        //if the counts are different, return false.
}  //checks to see if two lists look the same

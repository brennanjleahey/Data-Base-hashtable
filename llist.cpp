using namespace std;
#include<iostream>
#include"llist.h" 

//PURPOSE: Sets rear and front to NULL and count to 0.
llist::llist()
{
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

// PURPOSE: To delete all the pointers left.
llist::~llist() 
{
  el_t OldNum;
 
  while(!isEmpty())
    deleteFront(OldNum); 
  
}

//PURPOSE: Checking if list is empty by checking if both front and rear are NULL and that Count = 0
bool llist::isEmpty() 
{
  return Front == NULL && Rear == NULL && Count == 0;
}

//PURPOSE: Displays all nodes
void llist::displayAll() 
{
  Node *ptr = Front;

  if(isEmpty()) //Special case: if the list is empty
    cout << "[ empty ]" << endl;

  else
    {
      while(ptr != NULL)
	{
	  cout << "[" << ptr->Elem << "] ";
	  ptr = ptr->Next;
	}
      cout << endl;
    }
}
  
//PURPOSE: Checks that front and rear are null and that count is 0. return true if all params are met.
//PARAMETER: The new element that we want to add to the rear of the list.
void llist::addRear(el_t NewNum) 
{
  if(isEmpty())
    {
      Front = new Node;
      Rear = Front;
      Rear->Next = NULL;
      Rear->Elem = NewNum;
      Count++;
    }
  else
    {
      Rear->Next = new Node;
      Rear = Rear->Next;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
      Count++;  
    }
}
//PURPOSE: Add an element to the front of the list
//PARAMETER: The element that we will add to the front of the list
void llist::addFront(el_t NewNum) 
{
  if (Front == NULL)     //make sure we are empty
    {   
      Front = new Node;   //make a new front node
      Front->Elem = NewNum;   //front-> elem is new filled with our new elem
      Front->Next = NULL;     //front->next shouldn't be pointing to anything
      Rear = Front;       //front and rear are still pointing to the same thing
    }
  else 
    {
      Node *x;        //make a new temp node x
      x = new Node;
      x->Next = Front;    //set x->next to front so it is added to the front
      Front = x;          //set front to x
      Front->Elem = NewNum;   //add the new elem
    }
  
  Count++;
}

//PURPOSE:  delete the front node and elem
//PARAMETER: The variable we will be passing the old elem to that will be deleted.
void llist::deleteFront(el_t& OldNum) 
{
  if(isEmpty())      //error case: make sure we have something to delete
    throw Underflow();
  
  else if (Count == 1)   //else, if there's only on elem
    {   
      OldNum = Front->Elem;   //set the returned variable to the old elem in the node.
      delete Front;       //delete the front elem
      Front = NULL;       //set front to NULL
      Rear = NULL;        //same with rear
      Count--;            //decrement count
    }
  else   //else, we have more than one node/elem
    {
      OldNum = Front->Elem;   //set the returned variable to the old elem in the node.
      Node *ptr;       //make a temporary node so we don't lose front.
      ptr = Front->Next;       //make the temp node->next point to the new front
     
      delete Front;   //delete front
    
      Front = ptr;     //set front to the temporary node (new front)
      Count--;
    }
}

//PURPOSE: delete the rear elem and pass the elem back
//PARAMETER: the variable that will receive the old elem
void llist::deleteRear(el_t& OldNum) 
{
  if (isEmpty())      //error case: check if empty
    throw Underflow();      //send error
  
  else if (Count == 1) //if only one elem/node is present
    {      
    OldNum = Rear->Elem;    //save the deleted elem
    delete Rear;            //delete rear
    Front = NULL;       //set rear and front to null
    Rear = NULL;
    Count--;        //decrement count 
    }
  else //else, we have more than one elem/node
    {    
      OldNum = Rear->Elem;    //save the old elem to be deleted.
      Node *p = Front;        //make a temporary pointer at front
      //  Make p go to the one right before rear (using while)
      while (p->Next != Rear)     //we need to move through the list until we reach rear
	{  
	  p = p->Next;        //keep moving until p->next = rear
	}	 
      delete Rear;    //delete rear
      Rear = p;       //make p the new rear
      Rear->Next = NULL;  //make p->next = null
      Count--;        //decrement count
	
    }
}
//PURPOSE: delete the elem/node you want.
//PARAMETER: The node you wish deleted and the variable to receive the old elem.
void llist::deleteIth(int I, el_t& OldNum) 
{
  if (I > Count || I < 1)     //make sure we have a valid number
    throw OutOfRange();
 
  else if (I == 1)        //if first elem, call the func
    deleteFront(OldNum);
  
  else if (I == Count)    //if the last elem, call the func
    deleteRear(OldNum);
  
  else       //else, it's in the middle
    {  
      Node *ptr = Front;    //make a temp point at p
      Node *ptrDelete = Front->Next;  //make a temp pointer at the next node after front
      
      for (int k = 1; k <= I-2; k++)     //go through the list one node at a time, until we hit our number-1
	{	
	  ptr = ptr->Next;
	  ptrDelete = ptrDelete->Next;
	}

      ptr->Next = ptrDelete->Next;  //then we want to make p->next to point to the elem after the one being deleted
      OldNum = ptrDelete->Elem;   //save the old elem
      delete ptrDelete;       //delete the node
      Count--;        //decrement count
    }
}

//PURPOSE: To add an element before the designated element
//PARAMETER: The designated elem and the variable we send the old number to
void llist::insertIth(int I, el_t newNum)
{
  if (I > Count+1 || I < 1)   //make sure we have a valid number for the list
    throw OutOfRange();
 
  else if (I == 1)        //else call the right func if it's the first elem
    addFront(newNum);
  
  else if (I == Count+1)  //else, call the right func if it's the last elem
    addRear(newNum);
  
  else
    {      //else it's somewhere in the middle
      Node *P;  //make a temp node at front to move through the list
      Node *temp;
      P = new Node;

      P->Elem = newNum;
      temp = Front;

      for (int K = 1; K <= I-2; K++)     //move through the list one node at a time
        {
	  temp = temp->Next;
        }

      P->Next = temp->Next;   //set that new node's->next to the temp node
      temp->Next = P;
      Count++;    //increment count
    }
}

//PURPOSE:
//PARAMETER:
llist::llist(const llist& Original)
{
  //  this->'s data members need to be initialized here first
  Front = NULL; Rear = NULL; Count = 0;
  //  this-> object has to be built up by allocating new cells
  //  and copying the values from Original into each cell as we did with
  //  operator= above. To do this,
  // this-> object has to be built up by allocating new cells with OtherOne elements (**)
  Node* P = new Node;  // MUST make a new node, so that the linked list is distinct
  P = Original.Front;
  while (P != NULL)  // a loop which repeats until you reach the end of OtherOne.
    {
      this->addRear(P->Elem);    //P’s element is added to this->
      P = P->Next;                         // Go to the next node in OtherOne
    }


  //  Nothing to return because this is a constructor.

}
//PURPOSE:
//PARAMETER:
llist& llist::operator=(const llist& OtherOne)
{
  el_t x;
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  if (&OtherOne != this)  // if not the same
    {
      // this-> object has to be emptied first.
      while (! this->isEmpty() )
        this->deleteRear(x);
      // this-> object has to be built up by allocating new cells with OtherOne elements (**)
      Node* P;  // local pointer for OtherOne
      P = OtherOne.Front;
      while (P != NULL)  // a loop which repeats until you reach the end of OtherOne.
        {
          this->addRear(P->Elem);    //P’s element is added to this->
          P = P->Next;                         // Go to the next node in OtherOne
        }
    }// end of if
  return *this;    // return the result unconditionally.  Note that the result is returned by reference.

}


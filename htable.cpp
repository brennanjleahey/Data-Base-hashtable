using namespace std;
#include <iostream>
#include "htable.h"


htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key)
{ return key % TSIZE;  }
//turn key into slot number, mod by the table size
// adds the element to the table and returns slot#
int htable::add(el_t element )
{
  int slot = hash(element.key);  // hash with the key part
  table[slot].addRear(element);  
}
//add person to tablem return slot number
// finds element using the skey and returns the found element itself
// or a blank element
el_t htable::find(int skey)
{ //go thru the LL to find the elem whos key matches what your searching with
 el_t E; // a blank element
 int slot = hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
 selement.key = skey;// initialize it with just the skey
 E = table[slot].search2(selement); // call slist's search2 with selement which returns the found element 
 return E; // return the found element from here
}

// d
void htable::displayTable()
{
  for (int i = 0; i < 37; i++)
    { cout << i << ":" ;   
      table[i].displayAll(); //call slist's displayAll
    }
}

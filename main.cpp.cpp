using namespace std;
#include "htable.h"
#include <iostream>

// note that the second constructor of el_t can be used to
// create key+name to add to the table.
int main()
{
string name;
int key;
int cnum;
string p;
htable T;

 cout << "Welcome to DataBase Storage. How many accounts would you like to add (>0,<37)" << endl;
 cin >> cnum;

  for(int i= 0; i < cnum; i++)
    {
      cout << "Enter Username: " <<endl ;
      cin >> name;

      cout << "Enter key: " << endl;
      cin>> key;

      cout << "Enter password: " << endl;
      cin>> p;

      el_t myElem(key, name, p); // initializes myElem function
      T.add(myElem);

    }
  T.displayTable(); //display the table

  while(key!= -1)
    {
      cout << endl;
      cout << "Enter in search key (-1 to quit): " ;
      cin >> key;

      if(key!=-1)
        {
          el_t myElem = T.find(key); //looks for key
          el_t compareElem(key, "", ""); // create elem to compare
          if(myElem == compareElem)
            {
              cout << "Found" << key << ":";
              cout << myElem << endl;
	    }

	  else 
	    {
	      cout << "Not found" << endl;
	    }
	}

       cout << "Enter a key to decrypt. (-1 to quit)";
       cin >> key;
       if (key != -1)
	 {
       el_t myElem = T.find(key); //looks for key
       el_t compareElem(key, "", ""); // create elem to compare
	 if(myElem == compareElem)
	   {
	     cout << endl;
	     myElem.decrypt(myElem);
	     cout << endl;
	   }
	 else
	   {
	     cout << "Not found" << endl;
	   }
	 }
	 }

}



#include "elem.h"
#include <string>
#include <cstring>

// blank element
el_t::el_t()
{
  key = 0;
  name = "";
  password = "";
}
string el_t::encrypt(string plain)
{string pStr;  
 pStr = plain;
 int size = pStr.size();
 char pChar [size];
 strcpy(pChar, pStr.c_str());
 
 for (int i = 0; i < size; i++)
   {
     pChar[i] = ((int)pChar[i]) + 2;
   }
 for (int i = 0; i < size; i++)
   {
     pStr[i] = pChar[i];
   } 
 return pStr;
}

// initializing constructor to create an el_t object 
el_t::el_t(int akey, string aname, string p)
{
  key = akey;
  name = aname;
  password = encrypt(p);
}
void el_t::decrypt(el_t E)
{
  string pStr;
  pStr = E.password;
  int size = pStr.size();
  char pChar [size];
  strcpy(pChar, pStr.c_str());

    for (int i = 0; i < size; i++)
      {
	pChar[i] = ((int)pChar[i]) - 2;
      }
    for (int i = 0; i < size; i++)
      {
	pStr[i] = pChar[i];
      }
    cout << pStr;
}
  
// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
  if (key == OtherOne.key) return true; else return false;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os << E.key << "+" << E.name << "+" << E.password;
  return os;  
}  


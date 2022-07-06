#include <iostream>
#include <string>

using namespace std;

int main()
{
  string toilet; cin >> toilet;
  int alwaysUp = 0, alwaysDown = 0, preference = 0;
  bool alUp = toilet.at(0) == 'U', alDown = toilet.at(0) == 'U', pref = toilet.at(0) == 'U';
  toilet = toilet.substr(1);

  for(char c : toilet)
  {
    if(c=='U')
    {
      if(!alUp)
      {
        alwaysUp++;
        alUp = true;
      }
      if(!alDown)
      {
        alwaysDown+=2;
        alDown = false;
      }
      else
      {
        alwaysDown++;
        alDown = false;
      }
      if(!pref)
      {
        preference++;
        pref = true;
      }
    }
    else
    {
      if(alUp)
      {
        alwaysUp+=2;
        alUp = true;
      }
      else
      {
        alwaysUp++;
        alUp = true;
      }
      if(alDown)
      {
        alwaysDown++;
        alDown = false;
      }
      if(pref)
      {
        preference++;
        pref = false;
      }
    }
  }
  printf("%d\n%d\n%d", alwaysUp, alwaysDown, preference);
  return 0;
}
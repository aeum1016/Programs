#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
  int cap, stops; scanf("%d %d", &cap, &stops);
  int curOn = 0;;

  while(stops--)
  {
    int getOff, getOn, wait; scanf("%d %d %d", &getOff, &getOn, &wait);
    if(getOff > curOn)
    {
      printf("impossible");
      return 0;
    }
    else curOn-=getOff;
    if(curOn + getOn > cap)
    {
      printf("impossible");
      return 0;
    }
    else curOn += getOn;
    if(curOn != cap && wait)
    {
      printf("impossible");
      return 0;
    }
  }
  if(curOn) printf("impossible");
  else printf("possible");
  return 0;
}
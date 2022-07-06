#include <stdio.h>
#include <cmath>

int main()
{
  int o; scanf("%d", &o);
  int seconds = 0;
  int minutes = 0;
  while(o--)
  {
    int second, minute; scanf("%d %d", &minute, &second);
    seconds+=second;
    minutes+=minute;
  }
  double avg = seconds/(minutes*60.0);
  if(avg > 1) printf("%.12f", avg);
  else printf("measurement error");
  return 0;
}
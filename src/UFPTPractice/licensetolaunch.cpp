#include <stdio.h>
#include <cmath>

int main()
{
  int d; scanf("%d", &d);
  int i = 0;
  long long min = 10E9, minDay = d;
  while(i < d)
  {
    int j; scanf("%d", &j);
    if(j == 0) 
    {
      printf("%d", i);
      return 0;
    }
    else{
      if(j < min)
      {
        minDay = i;
        min = j;
      }
    }
    i++;
  }
  printf("%d", minDay);
  return 0;
}
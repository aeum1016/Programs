#include <stdio.h>

int main()
{
  int year; scanf("%d", &year);
  
  for(int i = 0; i < 12; i++)
  {
    if((((year*12)+i)-((2018*12)+3))%26 == 0)
    {
      printf("yes");
      return 0;
    }
  }
  printf("no");
  return 0;
}
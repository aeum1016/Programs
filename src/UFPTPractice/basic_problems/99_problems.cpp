#include <stdio.h>

int main()
{
  int i; scanf("%d", &i);
  if(i <= 99) 
  {
    printf("99");
    return 0;
  }

  int rem = i % 100;
  printf("%d", i + (rem >= 49 ? 99-rem : -(rem+1)));
  return 0;
}
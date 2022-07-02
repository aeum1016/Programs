#include <stdio.h>
#include <string.h>

int main()
{
  int n; scanf("%d", &n);

  char p1[20], p2[20]; scanf("%s %s", p1, p2);
  n-=2;

  bool increasing = (strcmp(p1, p2) < 0);
  while(n--)
  {
    *p1 = *p2;
    scanf("%s", p2);
    if((strcmp(p1, p2) < 0) != increasing)
    {
      printf("NEITHER");
      return 0;
    }
  }
  printf("%s", increasing ? "INCREASING" : "DECREASING");
  return 0;
}
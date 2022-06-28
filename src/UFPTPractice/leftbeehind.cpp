#include <stdio.h>

int main()
{
  while(true)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    if(a + b == 0) return 0;
    if(a + b == 13) printf("Never speak again.\n");
    else if(a > b) printf("To the convention.\n");
    else if (a == b) printf("Undecided.\n");
    else if (a < b) printf("Left beehind.\n");
  }
  return 0;
}
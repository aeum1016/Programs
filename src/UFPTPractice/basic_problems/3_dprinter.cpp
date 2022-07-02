#include <stdio.h>
#include <cmath>

int main()
{
  int p; scanf("%d", &p);
  printf("%d", (int) ceil(log2(p))+1);
}
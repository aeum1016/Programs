#include <stdio.h>

int main()
{
  int n; scanf("%d", &n);

  int count = 0;
  int bases = 0;
  while(n--)
  {
    int ab; scanf("%d", &ab);
    if(ab == -1) continue;
    else
    {
      bases += ab;
      count++;
    }
  }

  printf("%.10f", bases/(double)count);
  return 0;
}
#include <stdio.h>
#include <cmath>

int main()
{
  int q;
  int i = 1;
  while(scanf("%d", &q) != EOF)
  {
    int min = 1000000, max = -1000000;
    while(q--)
    {
      int p; scanf("%d", &p);
      min = std::fmin(p, min);
      max = std::fmax(p, max);
    }
    printf("Case %d: %d %d %d\n", i++, min, max, max-min);
  }
  return 0;
}
#include <stdio.h>
#include <cmath>

int main()
{
  int q; scanf("%d", &q);

  while(q--)
  {
    int sum, dif; scanf("%d %d", &sum, &dif);

    double a = (sum+dif) / 2.0;
    double b = sum - a;

    if(a >= 0 && a == (int)a && b >= 0 && b == (int)b)
    {
      printf("%d %d\n", (int)a, (int)b);
    }
    else
    {
      printf("impossible\n");
    }

  }
}
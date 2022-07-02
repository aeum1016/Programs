#include <stdio.h>
#include <cmath>
#define PI 3.14159265

double function(int p, int a, int b, int c, int d, int k)
{
  return (double) p * (std::sin(a * k + b) + std::cos(c * k + d) + 2.0);
}

int main()
{
  int p, a, b, c, d, n; scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);

  int i = 0;
  double drop = 0.0;
  double max = 0.0;
  while(i++ < n)
  {
    double price = function(p, a, b, c, d, i);
    max = std::fmax(max, price);
    drop = std::fmax(drop, max - price);
  }

  printf("%.9f", drop);

  return 0;
}
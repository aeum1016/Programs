#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int main()
{
  int M, N; 
  double R; scanf("%d %d %lf", &M, &N, &R);

  int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

  double minDist = 10E9;
  for(int i = fmin(y1, y2); i >= 0; i--)
  {
    double dist = ((abs(y1-y2) + ((fmin(y1, y2) - i)*2)) / (double) N) * R;
    dist += ((abs(x1-x2) / (double) M)) * ((i / (double) N) * R) * 3.14159265359;
    minDist = fmin(minDist, dist);
  }
  printf("%.14f", minDist);

  return 0;
}
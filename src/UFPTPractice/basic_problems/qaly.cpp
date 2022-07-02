#include <stdio.h>

int main(){
  int n; scanf("%d", &n);

  double qaly = 0;
  while(n--)
  {
    float q, y; scanf("%f %f", &q, &y);
    qaly += q*y;
  }
  printf("%f", qaly);
  return 0;
}
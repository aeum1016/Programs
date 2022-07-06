#include <stdio.h>
#include <cmath>

int main()
{
  int a, b; scanf("%d\n%d", &a, &b);
  if(abs(a-b) > 180)
  {
    if(fmin(a, b) == a) a+=360;
    else b+=360;
  }
  if(b-a == -180) printf("180");
  else printf("%d", b-a);
  return 0;
}
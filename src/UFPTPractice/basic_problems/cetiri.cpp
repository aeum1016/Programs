#include <stdio.h>
#include <cmath>

int main()
{
  int a, b, c; scanf("%d %d %d", &a, &b, &c);
  int min = std::fmin(a, std::fmin(b, c));
  int max = std::fmax(a, std::fmax(b, c));
  int mid = !(a == min || a == max) ? a : !(b == min || b == max) ? b : c;
  int multdif = max - min;
  if(max - multdif/2.0 == mid) printf("%d", max + multdif/2);
  else{
    if(max - multdif/3 == mid) printf("%d", min + multdif/3);
    else printf("%d", max - multdif/3);
  }
  return 0;
}
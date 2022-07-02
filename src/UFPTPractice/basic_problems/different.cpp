#include <stdio.h>
#include <cmath>

int main(){
  long long a, b;
  while(scanf("%lld %lld", &a, &b) != EOF)
  {
    long long c = std::abs(a-b);
    printf("%lld\n", c);
  }
  return 0;
}
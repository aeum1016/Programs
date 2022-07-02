#include <stdio.h>

int main(){
  int X, M;
  scanf("%d\n%d", &X, &M);
  int A = X;
  while(M--)
  {
    int m; scanf("%d", &m);
    A += X-m;
  }
  printf("%d", A);
  return 0;
}
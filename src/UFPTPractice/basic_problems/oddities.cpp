#include <stdio.h>

int main(){
  int q; scanf("%d", &q);
  while(q--)
  {
    int x; scanf("%d", &x);
    if(x%2) printf("%d is odd\n", x);
    else printf("%d is even\n", x);
  }
  return 0;
}
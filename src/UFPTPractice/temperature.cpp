#include <stdio.h>

int main(){
  int x, y; scanf("%d %d", &x, &y);
  if(y == 1 && x != 0) printf("IMPOSSIBLE");
  else if(y == 1) printf("ALL GOOD");
  else {
    y--;
    printf("%.10f", -((x/(double)y))); // number of movements
  }
  return 0;
}
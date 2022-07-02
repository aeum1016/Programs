#include <stdio.h>
#include <algorithm>

int main(){
  int l, r; scanf("%d %d", &l, &r);

  if(!l && !r) printf("Not a moose");
  else if(l == r) printf("Even %d", l*2);
  else printf("Odd %d", std::max(l, r) * 2);

  return 0;
}
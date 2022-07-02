#include <stdio.h>
#include <cmath>

int main(){
  int l, r; scanf("%d %d", &l, &r);
  if(l < r) 
  {
    printf("Dr. Chaz will have %d piece", r-l);
    if(r-l != 1) printf("s");
    printf(" of chicken left over!"); 
  }
  else 
  {
    printf("Dr. Chaz needs %d more piece", l-r);
    if(l-r != 1) printf("s");
    printf(" of chicken!");
  }
  return 0;
}
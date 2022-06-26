#include <stdio.h>

int main()
{
  int g, s, c; scanf("%d %d %d", &g, &s, &c);
  int bp = g*3 + s*2 + c;
  int vc = 0; 
  if(bp >= 8) {vc = 3; printf("Province or ");}
  else if(bp >= 5) {vc = 2; printf("Duchy or ");}
  else if(bp >= 2) {vc = 1; printf("Estate or ");}

  int tc = 1;
  if(bp >= 6) {tc = 3; printf("Gold");}
  else if(bp >= 3) {tc = 2; printf("Silver");}
  else printf("Copper");


}
#include <stdio.h>

int main()
{
  int q; scanf("%d", &q);
  while(q--)
  {
    int gn; scanf("%d", &gn);
    int i = 0;
    int prev = -1;
    while(i++ < gn)
    {
      int cur; scanf("%d", &cur);
      // printf("%d %d\n", gn, cur);
      if(cur != prev+1 && prev != -1) 
      {
        printf("%d\n", i);
      }
      else{
        prev = cur;
      }
    }
  }
  return 0;
}
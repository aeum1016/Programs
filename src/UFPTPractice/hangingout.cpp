#include <stdio.h>
#include <string.h>

int main()
{
  int limit, q; scanf("%d %d", &limit, &q);
  int curCount = 0;
  int rejected = 0;

  while(q--)
  {
    char enter[] = "enter";
    char event[6];
    int num;
    scanf("%s %d", event, &num);
    if(strcmp(enter, event) == 0)
    {
      if(limit < num + curCount)
      {
        rejected++;
      }
      else{
        curCount += num;
      }
    }
    else
    {
      curCount -= num;
    }
  }
  printf("%d", rejected);
}
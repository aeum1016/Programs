#include <stdio.h>
#include <cmath>
int main()
{
  int x1, y1, x2, y2;
  while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != EOF)
  {
    if(x1 == 0) break;
    int score1, score2;
    if(x1+y1 == 3) score1=100;
    else if(x1==y1) score1 = 90+x1;
    else score1 = (std::fmax(x1, y1) * 10) + std::fmin(x1, y1);
    if(x2+y2 == 3) score2=100;
    else if(x2==y2) score2 = 90+x2;
    else score2 = (std::fmax(x2, y2) * 10) + std::fmin(x2, y2);

    if(score1 == score2) printf("Tie.\n");
    else printf("Player %d wins.\n", score1 > score2 ? 1 : 2);
  }
  return 0;
}
#include <stdio.h>

int main()
{
  int q; scanf("%d", &q);
  while(q--)
  {
    int c; scanf("%d", &c);
    int totalVotes = 0;
    bool winner = true;
    int winnerNum = 0;
    int winnerBallots = 0;
    int i = 1;
    while(i <= c)
    {
      int votes; scanf("%d", &votes);
      if(votes > winnerBallots)
      {
        winner = true;
        winnerNum = i;
        winnerBallots = votes;
      }
      else if(votes == winnerBallots)
      {
        winner = false;
      }
      totalVotes += votes;
      i++;
    }

    if(winner)
    {
      printf("%s winner %d\n", winnerBallots/(double)totalVotes > .5 ? "majority" : "minority", winnerNum);
    }
    else{
      printf("no winner\n");
    }
  }
  return 0;
} 

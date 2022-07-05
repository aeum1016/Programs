#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

// more O's than X's is a no
// O = X and X has a 3 in a row is a no
// More Xs than Os and O has a 3 in a row is a no
// Two or more 3 in a rows on the board is a no

vector<int> checkForWins(vector<vector<int>> board)
{
  //Check for horizontals
  vector<int> wins(3);
  for(int i = 0; i < 3; i++)
  {
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
    {
      wins[board[i][0]]++;
    }
  }
  for(int j = 0; j < 3; j++)
  {
    if(board[0][j] == board[1][j] && board[0][j] == board[2][j])
    {
      wins[board[0][j]]++;
    }
  }
  if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) wins[board[1][1]]++;
  if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) wins[board[1][1]]++;

  return wins;
}

int main()
{
  vector<vector<int>> board(3, vector<int>(3,0));
  int n; scanf("%d\n", &n);
  while(n--)
  {
    int xCount = 0, oCount = 0;
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        char c; cin >> c;
        if(c == 'X') 
        {
          board[i][j] = 1;
          xCount++;
        }
        else if(c == 'O') 
        {
          board[i][j] = 2;
          oCount++;
        }
        else board[i][j] = 0;
      }
    }

    bool possible = true;
    vector<int> wins = checkForWins(board);

    if(xCount - oCount > 1) possible = false;
    if(xCount < oCount) possible = false;
    if(wins[1] + wins[2] > 1) possible = false;
    if(wins[1] && xCount == oCount) possible = false;
    if(xCount > oCount && wins[2]) possible = false;
    if(wins[1] == 2 && oCount == 4) possible = true;

    if(possible) printf("yes\n");
    else printf("no\n");
  }
  return 0;
}
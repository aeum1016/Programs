#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

  vector<vector<int>> board(8, vector<int>(8));
  vector<int> curPos;
  vector<int> diaPos;

  for(int i = 0; i < 8; i++)
  {
    string line;
    getline(cin, line);
    int j = 0;
    for(char c : line)
    {
      int square;
      if(c == '.') square = 0;
      else if(c == 'C') square = 1;
      else if(c == 'I') square = 2;
      else if(c == 'D') 
      {
        diaPos = vector<int>({i, j});
        square = 3;
      }
      else 
      {
        curPos = vector<int>({i, j});
        square = 4;
      }
      board[i][j] = square;
      j++;
    }
  }
  string command;
  getline(cin, command);

  vector<vector<int>> dir({{0, 1}, {1, 0}, {0, -1}, {-1, 0}});
  int curDir = 0;

  for(char c : command)
  {
    if(c == 'F')
    {
      vector<int> newSquare({curPos[0]+dir[curDir][0], curPos[1]+dir[curDir][1]});
      if(curPos[0]+dir[curDir][0] >= 8 
          || curPos[0]+dir[curDir][0] < 0
          || curPos[1]+dir[curDir][1] >= 8
          || curPos[1]+dir[curDir][1] < 0
          || board[newSquare[0]][newSquare[1]] == 1 
          || board[newSquare[0]][newSquare[1]] == 2
        )
      {
        printf("Bug!");
        return 0;
      }
      else
      {
        curPos = newSquare;
      }
    }
    else if(c == 'L')
    {
      curDir = (4+curDir-1) % 4;
    }
    else if(c == 'R')
    {
      curDir = (curDir+1) % 4;
    }
    else
    {
      vector<int> newSquare({curPos[0]+dir[curDir][0], curPos[1]+dir[curDir][1]});
      if(curPos[0]+dir[curDir][0] >= 8 
          || curPos[0]+dir[curDir][0] < 0
          || curPos[1]+dir[curDir][1] >= 8
          || curPos[1]+dir[curDir][1] < 0
          || board[newSquare[0]][newSquare[1]] != 2
      )
      {
        printf("Bug!");
        return 0;
      }
      else
      {
        board[newSquare[0]][newSquare[1]] = 0;
      }
    }
  }
  if(curPos == diaPos) printf("Diamond!");
  else printf("Bug!");
  return 0;
}
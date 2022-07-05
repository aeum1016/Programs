#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

int main()
{
  string white;
  string black;
  getline(cin, white);
  white = white.substr(7);
  unordered_map<string, char> pieces;
  stringstream whitess(white);
  string piece;
  while(getline(whitess, piece, ','))
  {
    if(piece.size() == 2)
    {
      pieces.emplace(piece, 'P');
    }
    else
    {
      pieces.emplace(piece.substr(1), piece.at(0));
    }
  }

  getline(cin, black);
  black = black.substr(7);
  stringstream blackss(black);
  while(getline(blackss, piece, ','))
  {
    if(piece.size() == 2)
    {
      pieces.emplace(piece, 'P' - ('A' - 'a'));
    }
    else
    {
      pieces.emplace(piece.substr(1), piece.at(0) - ('A' - 'a'));
    }
  }
  cout << "+---+---+---+---+---+---+---+---+" << endl;
  for(int i = 7; i >= 0; i--)
  {
    for(int j = 0; j < 8; j++)
    {
      cout << '|';
      cout << ((j+i)%2 ? '.' : ':');
      string piece = (char)(j+'a') + to_string(i+1);
      if(pieces.find(piece) != pieces.end())
      {
        cout << pieces.at(piece);
      }
      else cout << ((j+i)%2 ? "." : ":");
      cout << ((j+i)%2 ? "." : ":");
    }
    cout << '|' << endl;
    cout << "+---+---+---+---+---+---+---+---+" << endl;
  }
}
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector> 
#include <algorithm>

using namespace std;

bool ascSort(string a, string b){ return a.at(2) < b.at(2); }
bool descSort(string a, string b){ return a.at(2) > b.at(2); }
bool ascSortP(string a, string b){ return a.at(1) < b.at(1); }
bool descSortP(string a, string b){ return a.at(1) > b.at(1); }

int main()
{
  vector<vector<string>> whitePieces(6);
  vector<vector<string>> blackPieces(6);
  for(int i = 0; i < 17; i++)
  {
    string row;
    getline(cin, row);
    if(!(i%2)) continue;
    else
    {
      for(int j = 0; j < 8; j++)
      {
        if(row.at((j*4)+2) != '.' && row.at((j*4)+2) != ':')
        {
          if(row.at((j*4)+2) > 'a' && row.at((j*4)+2) < 'z')
          {
            string rowV = "1"; rowV.at(0)+=7-(i/2);
            string col = "a"; col.at(0)+=j;
            string piece = " "; piece.at(0) += row.at((j*4)+2) + 'A' - 'a';
            if(piece == "p") blackPieces[5].push_back(col + rowV);
            else if(piece == "k") blackPieces[0].push_back("K"+col+rowV);
            else if(piece == "q") blackPieces[1].push_back("Q"+col+rowV);
            else if(piece == "r") blackPieces[2].push_back("R"+col+rowV);
            else if(piece == "b") blackPieces[3].push_back("B"+col+rowV);
            else if(piece == "n") blackPieces[4].push_back("N"+col+rowV);
          }
          else
          {
            string rowV = "1"; rowV.at(0)+=7-(i/2);
            string col = "a"; col.at(0)+=j;
            string piece = " "; piece.at(0) += row.at((j*4)+2) + 'A' - 'a';
            if(piece == "P") whitePieces[5].push_back(col + rowV);
            else if(piece == "K") whitePieces[0].push_back("K"+col+rowV);
            else if(piece == "Q") whitePieces[1].push_back("Q"+col+rowV);
            else if(piece == "R") whitePieces[2].push_back("R"+col+rowV);
            else if(piece == "B") whitePieces[3].push_back("B"+col+rowV);
            else if(piece == "N") whitePieces[4].push_back("N"+col+rowV);
          }
        }
      }
    }
  }

  for(int i = 0; i < 5; i++)
  {
    sort(whitePieces[i].begin(), whitePieces[i].end(), ascSort);
  }
  sort(whitePieces[5].begin(), whitePieces[5].end(), ascSortP);

  cout << "White: ";
  string whitePieceString = "";
  if(!whitePieces.at(0).empty())
  {
    for(string p : whitePieces.at(0))
    {
      if(whitePieceString.length() != 0)
      {
        whitePieceString.append(",");
      }
      whitePieceString.append(p);
    }
  }
  if(!whitePieces.at(1).empty())
  {
    for(string p : whitePieces.at(1))
    {
      if(whitePieceString.length() != 0)
      {
        whitePieceString.append(",");
      }
      whitePieceString.append(p);
    }
  }
  if(!whitePieces.at(2).empty())
  {
    for(string p : whitePieces.at(2))
    {
      if(whitePieceString.length() != 0)
      {
        whitePieceString.append(",");
      }
      whitePieceString.append(p);
    }
  }
  if(!whitePieces.at(3).empty())
  {
    for(string p : whitePieces.at(3))
    {
      if(whitePieceString.length() != 0)
      {
        whitePieceString.append(",");
      }
      whitePieceString.append(p);
    }
  }
  if(!whitePieces.at(4).empty())
  {
    for(string p : whitePieces.at(4))
    {
      if(whitePieceString.length() != 0)
      {
        whitePieceString.append(",");
      }
      whitePieceString.append(p);
    }
  }
  if(!whitePieces.at(5).empty())
  {
    for(string p : whitePieces.at(5))
    {
      if(whitePieceString.length() != 0)
      {
        whitePieceString.append(",");
      }
      whitePieceString.append(p);
    }
  }
  cout << whitePieceString << endl;

    for(int i = 0; i < 5; i++)
  {
    sort(blackPieces[i].begin(), blackPieces[i].end(), descSort);
  }
  sort(blackPieces[5].begin(), blackPieces[5].end(), descSortP);

  cout << "Black: ";
  string blackPieceString = "";
  if(!blackPieces.at(0).empty())
  {
    for(string p : blackPieces.at(0))
    {
      if(blackPieceString.length() != 0)
      {
        blackPieceString.append(",");
      }
      blackPieceString.append(p);
    }
  }
  if(!blackPieces.at(1).empty())
  {
    for(string p : blackPieces.at(1))
    {
      if(blackPieceString.length() != 0)
      {
        blackPieceString.append(",");
      }
      blackPieceString.append(p);
    }
  }  if(!blackPieces.at(2).empty())
  {
    for(string p : blackPieces.at(2))
    {
      if(blackPieceString.length() != 0)
      {
        blackPieceString.append(",");
      }
      blackPieceString.append(p);
    }
  }  if(!blackPieces.at(3).empty())
  {
    for(string p : blackPieces.at(3))
    {
      if(blackPieceString.length() != 0)
      {
        blackPieceString.append(",");
      }
      blackPieceString.append(p);
    }
  }  if(!blackPieces.at(4).empty())
  {
    for(string p : blackPieces.at(4))
    {
      if(blackPieceString.length() != 0)
      {
        blackPieceString.append(",");
      }
      blackPieceString.append(p);
    }
  }  if(!blackPieces.at(5).empty())
  {
    for(string p : blackPieces.at(5))
    {
      if(blackPieceString.length() != 0)
      {
        blackPieceString.append(",");
      }
      blackPieceString.append(p);
    }
  }
  cout << blackPieceString << endl;

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unordered_map<string, int> votes;
  int maxVotes = 0;
  string winner = "Runoff!";

  string vote;
  while(getline(cin, vote))
  {
    if(votes.find(vote) != votes.end())
    {
      int newV = ++votes[vote];
      if(newV > maxVotes)
      {
        maxVotes = newV;
        winner = vote;
      }
      else if(newV == maxVotes)
      {
        winner = "Runoff!";
      }
    }
    else
    {
      votes.emplace(vote, 1);
      if(1 > maxVotes)
      {
        maxVotes = 1;
        winner = vote;
      }
      else if(1 == maxVotes)
      {
        winner = "Runoff!";
      }
    }
  }
  cout << winner;
  return 0;
}
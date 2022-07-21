#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

class Song
{
  public:
    vector<string> songs;
    int index;
};

int main()
{
  vector<string> titles;
  string a;
  getline(cin, a);
  stringstream aSS(a);
  while(getline(aSS, a, ' '))
  {
    titles.push_back(a);
  }
  int q; scanf("%d\n", &q);
  vector<Song*> songs;
  while(q--)
  {
    vector<string> song;
    string b;
    getline(cin, b);
    stringstream bSS(b);
    while(getline(bSS, b, ' '))
    {
      song.push_back(b);
    }
    Song* newSong = new Song();
    newSong->songs = song;
    songs.push_back(newSong);
  }
  scanf("%d\n", &q);
  while(q--)
  {
    string title;
    cin >> title;
    int theIndex = find(titles.begin(), titles.end(), title) - titles.begin();
    for(Song* s : songs)
    {
      s->index = theIndex;
    }
    stable_sort(songs.begin(), songs.end(), 
    [](const Song* a, const Song* b) -> bool
    { 
      return a->songs.at(a->index) < b->songs.at(b->index);
    });

    for(string cat : titles)
    {
      cout << cat << " ";
    }
    cout << endl;
    for(Song* s : songs)
    {
      for(string cat : s->songs)
      {
        cout << cat << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
}
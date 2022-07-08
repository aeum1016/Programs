#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int notes; scanf("%d\n", &notes);
  vector<char> note(notes);
  vector<int> time(notes);
  int curTime = 0;
  while(notes)
  {
    string n;
    cin >> n;
    if(n.size() == 1)
    {
      note[note.size()-notes] = n.at(0);
      time[note.size()-notes] = 1;
      curTime = curTime+2;
    }
    else
    {
      note[note.size()-notes] = n.at(0);
      time[note.size()-notes] = stoi(n.substr(1));
      curTime = curTime + stoi(n.substr(1))+1;
    }
    notes--;
  }

  for(int i = 0; i < 7; i++)
  {
    char n = 'G'-i;
    cout << n << ": ";
    for(int j = 0; j < note.size(); j++)
    {
      int passedTime = time[j];
      if(note[j] == n)
      {
        for(int k = 0; k < passedTime; k++)
        {
          cout << '*';
        }
      }
      else
      {
        for(int k = 0; k < passedTime; k++)
        {
          cout << (i%2 ? "-" : " ");
        }
      }
      if(j != note.size()-1) 
      {
        cout << (i%2 ? "-" : " ");
      }
    }
    cout << endl;
  }
  for(int i = 0; i < 7; i++)
  {
    char n = 'g'-i;
    cout << n << ": ";
    for(int j = 0; j < note.size(); j++)
    {
      int passedTime = time[j];
      if(note[j] == n)
      {
        for(int k = 0; k < passedTime; k++)
        {
          cout << '*';
        }
      }
      else
      {
        for(int k = 0; k < passedTime; k++)
        {
          cout << ((i == 0 || i == 2 || i == 6) ? "-" : " ");
        }
      }
      if(j != note.size()-1) 
      {
        cout << ((i == 0 || i == 2 || i == 6) ? "-" : " ");
      }
    }
    cout << endl;
  }
  return 0;
}
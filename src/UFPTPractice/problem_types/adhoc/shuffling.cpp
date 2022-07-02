#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int c; scanf("%d", &c);
  string op; cin >> op;
  vector<int> orig, chng;
  while(c--)
  {
    orig.push_back(c);
    chng.push_back(c);
  }
  
  int ops = 0;

  if(chng.size()<1) 
  {
    printf("1");
    return 0;
  }

  while(chng != orig || ops == 0)
  {
    ops++;
    if(op == "out")
    {
      vector<int> front = vector<int>(chng.begin(), chng.begin()+(chng.size()+1)/2);
      vector<int> back = vector<int>(chng.begin()+(chng.size()+1)/2, chng.end());
      for(int i = 0; i < chng.size(); i++)
      {
        if(i%2) chng[i] = back.at(i/2);
        else chng[i] = front.at(i/2);
      }
    }
    else
    {
      vector<int> front = vector<int>(chng.begin(), chng.begin()+(chng.size())/2);
      vector<int> back = vector<int>(chng.begin()+(chng.size())/2, chng.end());
      for(int i = 0; i < chng.size(); i++)
      {
        if(i%2) chng[i] = front.at(i/2);
        else chng[i] = back.at(i/2);
      }
    }
  }
  printf("%d", ops);
}
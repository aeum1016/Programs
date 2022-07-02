#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
  int c; scanf("%d", &c);
  int t; scanf("%d", &t);

  unordered_map<string, int> once;
  unordered_set<string> found;

  int i = 0;
  while(i < t)
  {
    i++;
    int a, b; scanf("%d %d", &a, &b);
    string one, two; cin >> one >> two;

    if(one == two)
    {
      if(found.find(one) != found.end()) found.erase(one);
      if(once.find(one) != once.end()) once.erase(one);
      c-=2;
    }
    else
    {
      if(once.find(one) != once.end())
      {
        if(found.find(one) == found.end())
        {
          if(once.at(one) != a)
          {
            found.emplace(one);
            once.erase(one);
          }
        }
      }
      else
      {
        if(found.find(one) == found.end())
        {
          once.emplace(one, a);
        }
      }

      if(once.find(two) != once.end())
      {
        if(found.find(two) == found.end())
        {
          if(once.at(two) != b)
          {
            found.emplace(two);
            once.erase(two);
          }
        }
      }
      else
      {
        if(found.find(two) == found.end())
        {
          once.emplace(two, b);
        }
      }
    }
  }

  if((c/2) == found.size()+once.size()) printf("%d", (c/2));
  else if((c/2) == found.size()+1) printf("%d", (c/2));
  else printf("%d", found.size());

  return 0;
}
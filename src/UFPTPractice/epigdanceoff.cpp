#include <vector>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n, m; scanf("%d %d\n", &n, &m);
  vector<bool> cols(m, true);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      char a; scanf("%c", &a);
      if(a == '$') 
      {
        cols[j] = false;
      }
    }
    char t; scanf("%c", &t);
  }

  int frames = 1;
  for(bool b : cols)
  {
    if(b) frames++;
  }
  printf("%d", frames);
  return 0;
}
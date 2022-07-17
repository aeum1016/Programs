#include <unordered_map>
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  int st; scanf("%d", &st);
  string a, b; cin >> a >> b;
  vector<int> letters(26, 0);
  int r = 0, s = 0;
  for(int i = 0; i < st; i++)
  {
    char ac = a.at(i);
    char bc = b.at(i);

    if(ac == bc) r++;
    else
    {
      letters.at(ac-'A')++;
      if(letters.at(ac-'A') <= 0) s++;
      letters.at(bc-'A')--;
      if(letters.at(bc-'A') >= 0) s++;
    }
  }
  printf("%d %d", r, s);
  return 0;
}
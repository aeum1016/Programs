#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int r; scanf("%d", &r);

  while(r--)
  {
    int i; scanf("%d\n", &i);
    string name;
    bool psoup = false, pancakes = false;
    getline(cin, name);
    while(i--)
    {
      string item;
      getline(cin, item);
      if(item == "pea soup") psoup = true;
      if(item == "pancakes") pancakes = true; 
    }
    if(psoup && pancakes)
    {
      cout << name;
      return 0;
    }
  }
  printf("Anywhere is fine I guess");
  return 0;
}
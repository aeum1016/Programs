#include <string>
#include <iostream>

using namespace std;

int main()
{
  string string1; cin >> string1;
  int count = 0;
  int ws = 0;
  int uc = 0;
  int lc = 0;
  int sm = 0;
  for(char c : string1)
  {
    if(c == '_')
    {
      ws++;
    }
    else if(c >= 'A' && c <= 'Z')
    {
      uc++;
    }
    else if(c >= 'a' && c <= 'z')
    {
      lc++;
    }
    else
    {
      sm++;
    }
    count++;
  }
  printf("%.15f\n%.15f\n%.15f\n%.15f", ws/(double) count, lc/(double) count, uc/(double) count, sm/(double) count);
  return 0;
}
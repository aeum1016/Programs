#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int h1, m1, s1;
  scanf("%d:%d:%d", &h1, &m1, &s1);
  int h2, m2, s2;
  scanf("%d:%d:%d", &h2, &m2, &s2);
  int secs1 = h1*3600 + m1*60 + s1;
  int secs2 = h2*3600 + m2*60 + s2;

  int dif = secs2 - secs1;
  if(dif < 1) dif += 24*3600;

  cout << setfill('0') << setw(2) << dif / 3600 << ':' << setw(2) << (dif%3600)/60 << ':' << setw(2) << ((dif%3600)%60);
  return 0;
}
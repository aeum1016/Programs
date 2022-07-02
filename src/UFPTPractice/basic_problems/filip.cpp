#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
  string a, b;
  cin >> a >> b;

  for (int i = 0; i < a.length() / 2; i++)
    swap(a[i], a[a.length() - i - 1]);
  for (int i = 0; i < b.length() / 2; i++)
    swap(b[i], b[b.length() - i - 1]);
  
  printf("%d", stoi(a) > stoi(b) ? stoi(a) : stoi(b));

  return 0;
}
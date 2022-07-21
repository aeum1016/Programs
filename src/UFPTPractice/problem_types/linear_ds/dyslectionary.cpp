#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool cmp(const string a, const string b)
{
  string aN(a.rbegin(), a.rend());
  string bN(b.rbegin(), b.rend());
  return aN < bN;
}

int main()
{
  string word;
  vector<string> strings;
  int max = 0;
  while(getline(cin, word))
  {
    if(word == "")
    {

      stable_sort(strings.begin(), strings.end(), cmp);
      for(int j = 0; j < strings.size(); j++)
      {
        cout << setfill(' ') << setw(max) << strings.at(j) << endl;
      }
      cout << endl;
      strings.clear();
      max = 0;
    }
    else
    {
      max = fmax(max, word.size());
      strings.push_back(word);
    }
  }
  stable_sort(strings.begin(), strings.end(), cmp);
  for(int j = 0; j < strings.size(); j++)
  {
    cout << setfill(' ') << setw(max) << strings.at(j) << endl;
  }
}